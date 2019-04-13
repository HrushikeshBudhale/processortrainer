#include <LedControl.h>

#define DEVICES 4
#define EXT_CLK 1
#define CLKPIN 1
#define MODEPIN 2
#define FREQPIN 3

// control outputs positions
#define ALUFN 0x0b
#define WERF 0x0a
#define BSEL 0x09
#define WDSEL 0x07
#define WR 0x06
#define RA2SEL 0x05
#define PCSEL 0x02
#define ASEL 0x01
#define WASEL 0x00

//########################## Global objects #################################
// DataIn, CLK, LOAD, No. of displays
//LedControl lc = LedControl(12,14,15,DEVICES);
LedControl lc = LedControl(12, 11, 10, DEVICES); // For arduino

//########################## Global variables ##############################

// General variables
String inputString = "";				// a String to hold incoming data
boolean stringComplete = false; // whether the string is complete
boolean codeReady = false;
boolean clkMode = false; // false if MODEPIN is set to EXT_CLK

// Data Containers
unsigned long int prog_data[20]; // 32 bit
unsigned long int reg_file[32];
unsigned long int data_mem[20];

// Address Containers
unsigned char PC = 0;			//
unsigned char opcode = 0; //
unsigned char Rc = 0;			// 8 bit
unsigned char Ra = 0;			//
unsigned char Rb = 0;			//
unsigned char z = 0;			//
unsigned int literal = 0; // 16 bit
int clkDelay = 0;

// Display related variabes
unsigned long int cntlOp;

// type-defination: 'funtionPrt' now can be used as type
typedef void (*fuctionPtr)(void);

// Declare an array of pointer to functions (i.e. lookup table)
fuctionPtr funcLookupTbl[40]; // Stores array of pointers to all functions

//###################### Function Declarations ############################
// Display related functions
void initAllDisplay(void);
void updateDisplay(String inString);
void setNum(int device, unsigned long int Data);

// Process related functions
void initLookupTbl(void);
int getClkDelay(void);
void execute(void);
void setClkDelay(void);
void makeCodeReady(void);

//############################### Main ####################################
void setup()
{
	// Initialise Display
	initAllDisplay();

	// Initialise Lookup Table
	initLookupTbl();

	// Set input pins
	pinMode(MODEPIN, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(MODEPIN), changeMode, CHANGE);
	pinMode(CLKPIN, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(CLKPIN), evaluate, RISING);
	pinMode(FREQPIN, INPUT);

	// Setup UART communication
	Serial.begin(115200);
	while (!Serial.available())
		; // wait for serial port to connect.
	Serial.println("Serial Communication OK!");

	makeCodeReady();
}

void loop()
{
}

// ISR to chage clock type status
void changeMode()
{
	clkMode = !clkMode;
}

/* void updateDisplay(void)
{
  setNum(0, prog_data[PC]);
  setNum(1,)
} */

void evaluate(void)
{
	if (codeReady && !clkMode)
	{
		// Start execution
		fetch();
		decode();
		execute();
		// updateDisplay();
	}
	Serial.println("========================================================");
}

void makeCodeReady(void)
{
	Serial.println("In makeCodeReady");
	codeReady = true;
	prog_data[0] = 0x77BF0002;
	prog_data[1] = 0x77BF0001;
	prog_data[2] = 0x77BF0000;
	prog_data[3] = 0xC01F0001;
	prog_data[4] = 0xC03F0001;
	prog_data[5] = 0x88000800;
	prog_data[6] = 0xC0210001;
	prog_data[7] = 0xD8410006;
	prog_data[8] = 0x7BA2FFFC;
	prog_data[9] = 0x641F0028;
	prog_data[10] = 0x77BFFFFF;
}

void setClkDelay(void)
{
	long int clkFreq;
	clkFreq = analogRead(FREQPIN); // 0 - 1024
	clkFreq = map(clkFreq, 1, 1024, 1, 1000);
	clkDelay = 10000 / clkFreq; // (10000 - 10) 10sec - 10milliSec
	Serial.print("Setting clock delay to ");
	Serial.println(clkDelay);
}

void fetch(void)
{
	Serial.println("In fetch");
	opcode = (prog_data[PC] >> 26);			 // bits 31 - 26
	Rc = ((prog_data[PC] >> 21) & 0x1f); // bits 25 - 21
	Ra = ((prog_data[PC] >> 16) & 0x1f); // bits 20 - 16
	Rb = ((prog_data[PC] >> 11) & 0x1f); // bits 15 - 11
	literal = (prog_data[PC] & 0xffff);	// bits 15 - 0
	Serial.print("opcode= ");
	Serial.print(opcode);
	Serial.print(", Rc= ");
	Serial.print(Rc);
	Serial.print(", Ra= ");
	Serial.print(Ra);
	Serial.print(", Rb= ");
	Serial.print(Rb);
	Serial.print(", literal= ");
	Serial.println(literal);
}

void decode(void)
{
	Serial.println("In decode");
	char code = opcode - 24;
	if (code > 7 && code < 24)
	{
		// OP
		Serial.println("cntl type OP");
		cntlOp = ((opcode << ALUFN) || (1 << WERF) || (1 << WDSEL));
	}
	else if (code > 23 && code < 40)
	{
		// OPC
		Serial.println("cntl type OPC");
		cntlOp = ((opcode << ALUFN) || (1 << WERF) || (1 << BSEL) || (1 << WDSEL));
	}
	else
	{
		switch (code)
		{
		case 0:
			// LD
			Serial.println("cntl type LD");
			cntlOp = ((8 << ALUFN) || (1 << WERF) || (1 << BSEL) || (2 << WDSEL));
			break;
		case 1:
			// ST
			Serial.println("cntl type ST");
			cntlOp = ((8 << ALUFN) || (1 << BSEL) || (1 << WR) || (1 << RA2SEL));
			break;
		case 3:
			// JMP
			Serial.println("cntl type JMP");
			cntlOp = ((1 << WERF) || (2 << PCSEL));
			break;
		case 5:
			// BEQ
			Serial.println("cntl type BEQ");
			if (z)
				cntlOp = ((1 << WERF) || (1 << PCSEL));
			else
				cntlOp = ((1 << WERF) || (0 << PCSEL));
			break;
		case 6:
			// BNE
			Serial.println("cntl type BNE");
			if (z)
				cntlOp = ((1 << WERF) || (0 << PCSEL));
			else
				cntlOp = ((1 << WERF) || (1 << PCSEL));
			break;
		case 7:
			// LDR
			Serial.println("cntl type LDR");
			cntlOp = ((1 << WERF) || (2 << WDSEL) || (1 << ASEL));
			break;
		default:
			// Illop
			Serial.println("cntl type Illop");
			cntlOp = ((1 << WERF) || (4 << PCSEL) || (1 << WASEL));
			break;
		}
	}
}

void execute(void)
{
	Serial.println("In execute");
	funcLookupTbl[opcode - 24](); // opcode starts from 24
}

void initAllDisplay(void)
{
	Serial.println("Initialised all Display");
	for (int i = 0; i < DEVICES; i++)
	{
		lc.shutdown(i, false);
		lc.setIntensity(i, 8);
		lc.clearDisplay(i);
		for (int j = 0; j < 8; j++)
		{
			lc.setDigit(i, j, 0, false);
		}
	}
}

/* void updateDisplay(String msg)
{
  int from;
  int device;
  unsigned long int Data;
  while (msg.indexOf(":") != -1)
  {
    from = msg.indexOf(":");
    device = (msg.substring(from - 1)).toInt();
    Data = (msg.substring(from + 1)).toInt();
    setNum(device, Data);

    from = msg.indexOf(","); // if next value is present
    if (from != -1)          // get next value
      msg = msg.substring(from + 1);
    else
      break;
  }
} */

void setNum(int device, unsigned long int Data)
{
	Serial.print("Setting ");
	Serial.print(Data);
	Serial.print(" at address ");
	Serial.println(device);

	for (int i = 7; i >= 0; i--)
	{
		lc.setDigit(device, i, (Data % 10), false);
		if (Data != 0)
			Data /= 10;
	}
}

void serialEvent()
{
	char inChar = (char)Serial.read();
	if (inChar == '\n')
	{
		stringComplete = true;
		switch (inputString.charAt(0))
		{
		case 's': //stops the controller
			run = 0;
			encoderValue = 0;
			setPWM(0);
			break;

		case 'r': //runs the controller
			run = 1;
			break;

		case 'e': //sets encoder value
			reqd_pos = inputString.substring(inputString.indexOf('=') + 1).toFloat();
			break;
		}
		Serial.println("\nPress 'r' to run");
	}
	else
		inputString += inChar;
}

void ADD(void)
{
	// Check what gives error and apply to rest
	Serial.println("Executing ADD");
	reg_file[Rc] = (unsigned int)(reg_file[Ra] + reg_file[Rb]);
	PC += 1;
}

void ADDC(void)
{
	Serial.println("Executing ADDC");
	reg_file[Rc] = reg_file[Ra] + literal;
	PC += 1;
}

void AND(void)
{
	Serial.println("Executing AND");
	reg_file[Rc] = reg_file[Ra] & reg_file[Rb];
	PC += 1;
}

void ANDC(void)
{
	Serial.println("Executing ANDC");
	reg_file[Rc] = reg_file[Ra] & literal;
	PC += 1;
}

void BEQ(void)
{
	Serial.println("Executing BEQ");
	PC += 1;
	reg_file[Rc] = PC;
	if (reg_file[Ra] == 0)
		PC += literal;
}

void BNE(void)
{
	Serial.println("Executing BNE");
	PC += 1;
	reg_file[Rc] = PC;
	if (reg_file[Ra] != 0)
		PC += literal;
}

void CMPEQ(void)
{
	Serial.println("Executing CMPEQ");
	PC += 1;
	if (reg_file[Ra] == reg_file[Rb])
		reg_file[Rc] = 1;
	else
		reg_file[Rc] = 0;
}

void CMPEQC(void)
{
	Serial.println("Executing CMPEQC");
	PC += 1;
	if (reg_file[Ra] == literal)
		reg_file[Rc] = 1;
	else
		reg_file[Rc] = 0;
}

void CMPLE(void)
{
	Serial.println("Executing CMPLE");
	PC += 1;
	if (reg_file[Ra] <= reg_file[Rb])
		reg_file[Rc] = 1;
	else
		reg_file[Rc] = 0;
}

void CMPLEC(void)
{
	Serial.println("Executing CMPLEC");
	PC += 1;
	if (reg_file[Ra] <= literal)
		reg_file[Rc] = 1;
	else
		reg_file[Rc] = 0;
}

void CMPLT(void)
{
	Serial.println("Executing CMPLT");
	PC += 1;
	if (reg_file[Ra] < reg_file[Rb])
		reg_file[Rc] = 1;
	else
		reg_file[Rc] = 0;
}

void CMPLTC(void)
{
	Serial.println("Executing CMPLTC");
	PC += 1;
	if (reg_file[Ra] < literal)
		reg_file[Rc] = 1;
	else
		reg_file[Rc] = 0;
}

void DIV(void)
{
	Serial.println("Executing DIV");
	reg_file[Rc] = reg_file[Ra] / reg_file[Rb];
	PC += 1;
}

void DIVC(void)
{
	Serial.println("Executing DIVC");
	reg_file[Rc] = reg_file[Ra] / literal;
	PC += 1;
}

void JMP(void)
{
	Serial.println("Executing JMP");
	PC += 1;
	reg_file[Rc] = PC;
	PC = reg_file[Ra] & 0xfffffffc;
}

void LD(void)
{
	Serial.println("Executing LD");
	PC += 1;
	reg_file[Rc] = data_mem[reg_file[Ra] + literal];
}

void LDR(void)
{
	Serial.println("Executing LDR");
	PC += 1;
	reg_file[Rc] = data_mem[PC + literal];
}

void MUL(void)
{
	Serial.println("Executing MUL");
	reg_file[Rc] = reg_file[Ra] * reg_file[Rb];
	PC += 1;
}

void MULC(void)
{
	Serial.println("Executing MULC");
	reg_file[Rc] = reg_file[Ra] * literal;
	PC += 1;
}

void OR(void)
{
	Serial.println("Executing OR");
	reg_file[Rc] = reg_file[Ra] | reg_file[Rb];
	PC += 1;
}

void ORC(void)
{
	Serial.println("Executing ORC");
	reg_file[Rc] = reg_file[Ra] | literal;
	PC += 1;
}

void SHL(void)
{
	Serial.println("Executing SHL");
	reg_file[Rc] = reg_file[Ra] << reg_file[Rb];
	PC += 1;
}

void SHLC(void)
{
	Serial.println("Executing SHLC");
	reg_file[Rc] = reg_file[Ra] << (literal & 0x1f);
	PC += 1;
}

void SHR(void)
{
	Serial.println("Executing SHR");
	reg_file[Rc] = reg_file[Ra] >> reg_file[Rb];
	PC += 1;
}

void SHRC(void)
{
	Serial.println("Executing SHRC");
	reg_file[Rc] = reg_file[Ra] >> (literal & 0x1f);
	PC += 1;
}

void SRA(void)
{ // Get Exact difference from above func.
	// Propagating sign bits to left (how to do it)
	Serial.println("Executing SRA");
	reg_file[Rc] = reg_file[Ra] >> reg_file[Rb];
	PC += 1;
}

void SRAC(void)
{
	Serial.println("Executing SRAC");
	reg_file[Rc] = reg_file[Ra] >> (literal & 0x1f);
	PC += 1;
}

void ST(void)
{
	Serial.println("Executing ST");
	PC += 1;
	data_mem[reg_file[Ra] + literal] = reg_file[Rc];
}

void SUB(void)
{
	Serial.println("Executing SUB");
	reg_file[Rc] = reg_file[Ra] - reg_file[Rb];
	PC += 1;
}

void SUBC(void)
{
	Serial.println("Executing SUBC");
	reg_file[Rc] = reg_file[Ra] - literal;
	PC += 1;
}

void XOR(void)
{
	Serial.println("Executing XOR");
	reg_file[Rc] = reg_file[Ra] ^ reg_file[Rb];
	PC += 1;
}

void XORC(void)
{
	Serial.println("Executing XORC");
	reg_file[Rc] = reg_file[Ra] ^ literal;
	PC += 1;
}

void NOPE()
{
	Serial.println("Executing NOPE");
	// Place holder
}

void initLookupTbl(void)
{
	Serial.println("Lookup table initialised!");
	funcLookupTbl[0] = LD;
	funcLookupTbl[1] = ST;
	funcLookupTbl[2] = NOPE;
	funcLookupTbl[3] = JMP;
	funcLookupTbl[4] = NOPE;
	funcLookupTbl[5] = BEQ;
	funcLookupTbl[6] = BNE;
	funcLookupTbl[7] = LDR;
	funcLookupTbl[8] = ADD;
	funcLookupTbl[9] = SUB;
	funcLookupTbl[10] = MUL;
	funcLookupTbl[11] = DIV;
	funcLookupTbl[12] = CMPEQ;
	funcLookupTbl[13] = CMPLT;
	funcLookupTbl[14] = CMPLE;
	funcLookupTbl[15] = NOPE;
	funcLookupTbl[16] = AND;
	funcLookupTbl[17] = OR;
	funcLookupTbl[18] = XOR;
	funcLookupTbl[19] = NOPE;
	funcLookupTbl[20] = SHL;
	funcLookupTbl[21] = SHR;
	funcLookupTbl[22] = SRA;
	funcLookupTbl[23] = NOPE;
	funcLookupTbl[24] = ADDC;
	funcLookupTbl[25] = SUBC;
	funcLookupTbl[26] = MULC;
	funcLookupTbl[27] = DIVC;
	funcLookupTbl[28] = CMPEQC;
	funcLookupTbl[29] = CMPLTC;
	funcLookupTbl[30] = CMPLEC;
	funcLookupTbl[31] = NOPE;
	funcLookupTbl[32] = ANDC;
	funcLookupTbl[33] = ORC;
	funcLookupTbl[34] = XORC;
	funcLookupTbl[35] = NOPE;
	funcLookupTbl[36] = SHLC;
	funcLookupTbl[37] = SHRC;
	funcLookupTbl[38] = SRAC;
	funcLookupTbl[39] = NOPE;
}
