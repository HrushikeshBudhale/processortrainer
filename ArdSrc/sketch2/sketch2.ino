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

//############## Global objects ###############
// DataIn, CLK, LOAD, No. of displays
//LedControl lc = LedControl(12,14,15,DEVICES);
LedControl lc = LedControl(12, 11, 10, DEVICES); // For arduino

//############## Global variables ###############

// General variables
String inputString = "";        // a String to hold incoming data
boolean stringComplete = false; // whether the string is complete

// Data Containers
unsigned long int prog_data[20]; // 32 bit
unsigned long int reg_file[32];
unsigned long int data_mem[20];

// Address Containers
unsigned char PC = 0;     //
unsigned char opcode = 0; //
unsigned char Rc = 0;     // 8 bit
unsigned char Ra = 0;     //
unsigned char Rb = 0;     //
unsigned char z = 0;      //
unsigned int literal = 0; // 16 bit
int clkDelay = 0;

// Display related variabes
unsigned long int cntlOp;

// type-defination: 'funtionPrt' now can be used as type
typedef void (*fuctionPtr)(void);

// Declare an array of pointer to functions (i.e. lookup table)
fuctionPtr funcLookupTbl[40];   // Stores array of pointers to all functions

//############## Function Declarations ###############
// Display related functions
void initAllDisplay(void);
void updateDisplay(String inString);
void setNum(int device, unsigned long int Data);

// Process related functions
void initLookupTbl(void);
int getClkDelay(void);
void execute(void);

//####################### Main ########################
void setup()
{
  // Initialise Display
  initAllDisplay();

  // Initialise Lookup Table
  initLookupTbl();

  // Set input pins
  pinMode(CLKPIN, INPUT);
  pinMode(MODEPIN, INPUT);
  pinMode(FREQPIN, INPUT);

  // Setup UART communication
  Serial.begin(57600);
  while (!Serial.available())
    ; // wait for serial port to connect.
  Serial.println("Serial Communication OK!");
}

void loop()
{
  fetch();
  decode();
  execute();
}

int setClkDelay(void){
    int clkFreq;
    clkFreq = analogRead(FREQPIN);   // 0 - 1024
    clkFreq = map(clkFreq, 1, 1000);    // 1 - 1000 Verify this function 
    clkDelay = 10000/clkFreq;   // (10000 - 10) 10sec - 10milliSec
    return(clkDelay);
}

void fetch(void)
{
  opcode = (prog_data[PC] >> 26);      // bits 31 - 26
  Rc = ((prog_data[PC] >> 21) & 0x1f); // bits 25 - 21
  Ra = ((prog_data[PC] >> 16) & 0x1f); // bits 20 - 16
  Rb = ((prog_data[PC] >> 11) & 0x1f); // bits 15 - 11
  literal = (prog_data[PC] & 0xffff);  // bits 15 - 0
}

void decode(void)
{
  char code = opcode - 24;
  if (code > 7 && code < 24)
  {
    // OP
    cntlOp = ((opcode << ALUFN) || (1 << WERF) || (1 << WDSEL));
  }
  else if (code > 23 && code < 40)
  {
    // OPC
    cntlOp = ((opcode << ALUFN) || (1 << WERF) || (1 << BSEL) || (1 << WDSEL));
  }
  else
  {
    switch (code)
    {
    case 0:
      // LD
      cntlOp = ((8 << ALUFN) || (1 << WERF) || (1 << BSEL) || (2 << WDSEL));
      break;
    case 1:
      // ST
      cntlOp = ((8 << ALUFN) || (1 << BSEL) || (1 << WR) || (1 << RA2SEL));
      break;
    case 3:
      // JMP
      cntlOp = ((1 << WERF) || (2 << PCSEL));
      break;
    case 5:
      // BEQ
      if (z)
        cntlOp = ((1 << WERF) || (1 << PCSEL));
      else
        cntlOp = ((1 << WERF) || (0 << PCSEL));
      break;
    case 6:
      // BNE
      if (z)
        cntlOp = ((1 << WERF) || (0 << PCSEL));
      else
        cntlOp = ((1 << WERF) || (1 << PCSEL));
      break;
    case 7:
      // LDR
      cntlOp = ((1 << WERF) || (2 << WDSEL) || (1 << ASEL));
      break;
    default:
      // Illop
      cntlOp = ((1 << WERF) || (4 << PCSEL) || (1 << WASEL));
      break;
    }
  }
}

void execute(void)
{
  funcLookupTbl[opcode - 24](); // opcode starts from 24
}

void initAllDisplay(void)
{
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
  for (int i = 7; i >= 0; i--)
  {
    lc.setDigit(device, i, (Data % 10), false);
    if (Data != 0)
      Data /= 10;
  }
}

/* void serialEvent()
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
} */

void initLookupTbl(void)
{
  funcLookupTbl[0] = LD;
  funcLookupTbl[1] = ST;
  funcLookupTbl[0] = NOP;
  funcLookupTbl[0] = JMP;
  funcLookupTbl[4] = NOP;
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
  funcLookupTbl[15] = NOP;
  funcLookupTbl[16] = AND;
  funcLookupTbl[17] = OR;
  funcLookupTbl[18] = XOR;
  funcLookupTbl[19] = NOP;
  funcLookupTbl[20] = SHL;
  funcLookupTbl[21] = SHR;
  funcLookupTbl[22] = SRA;
  funcLookupTbl[23] = NOP;
  funcLookupTbl[24] = ADDC;
  funcLookupTbl[25] = SUBC;
  funcLookupTbl[26] = MULC;
  funcLookupTbl[27] = DIVC;
  funcLookupTbl[28] = CMPEQC;
  funcLookupTbl[29] = CMPLTC;
  funcLookupTbl[30] = CMPLEC;
  funcLookupTbl[31] = NOP;
  funcLookupTbl[32] = ANDC;
  funcLookupTbl[33] = ORC;
  funcLookupTbl[34] = XORC;
  funcLookupTbl[35] = NOP;
  funcLookupTbl[36] = SHLC;
  funcLookupTbl[37] = SHRC;
  funcLookupTbl[38] = SRAC;
  funcLookupTbl[39] = NOP;
}

void ADD(void)
{
  // Check what gives error and apply to rest
  reg_file[Rc] = (unsigned int)(reg_file[Ra] + reg_file[Rb]);
  PC += 1;
}

void ADDC(void)
{
  reg_file[Rc] = reg_file[Ra] + literal;
  PC += 1;
}

void AND(void)
{
  reg_file[Rc] = reg_file[Ra] & reg_file[Rb];
  PC += 1;
}

void ANDC(void)
{
  reg_file[Rc] = reg_file[Ra] & literal;
  PC += 1;
}

void BEQ(void)
{
  PC += 1;
  reg_file[Rc] = PC;
  if (reg_file[Ra] == 0)
    PC += literal;
}

void BNE(void)
{
  PC += 1;
  reg_file[Rc] = PC;
  if (reg_file[Ra] != 0)
    PC += literal;
}

void CMPEQ(void)
{
  PC += 1;
  if (reg_file[Ra] == reg_file[Rb])
    reg_file[Rc] = 1;
  else
    reg_file[Rc] = 0;
}

void CMPEQC(void)
{
  PC += 1;
  if (reg_file[Ra] == literal)
    reg_file[Rc] = 1;
  else
    reg_file[Rc] = 0;
}

void CMPLE(void)
{
  PC += 1;
  if (reg_file[Ra] <= reg_file[Rb])
    reg_file[Rc] = 1;
  else
    reg_file[Rc] = 0;
}

void CMPLEC(void)
{
  PC += 1;
  if (reg_file[Ra] <= literal)
    reg_file[Rc] = 1;
  else
    reg_file[Rc] = 0;
}

void CMPLT(void)
{
  PC += 1;
  if (reg_file[Ra] < reg_file[Rb])
    reg_file[Rc] = 1;
  else
    reg_file[Rc] = 0;
}

void CMPLTC(void)
{
  PC += 1;
  if (reg_file[Ra] < literal)
    reg_file[Rc] = 1;
  else
    reg_file[Rc] = 0;
}

void DIV(void)
{
  reg_file[Rc] = reg_file[Ra] / reg_file[Rb];
  PC += 1;
}

void DIVC(void)
{
  reg_file[Rc] = reg_file[Ra] / literal;
  PC += 1;
}

void JMP(void)
{
  PC += 1;
  reg_file[Rc] = PC;
  PC = reg_file[Ra] & 0xfffffffc;
}

void LD(void)
{
  PC += 1;
  reg_file[Rc] = data_mem[reg_file[Ra] + literal];
}

void LDR(void)
{
  PC += 1;
  reg_file[Rc] = data_mem[PC + literal];
}

void MUL(void)
{
  reg_file[Rc] = reg_file[Ra] * reg_file[Rb];
  PC += 1;
}

void MULC(void)
{
  reg_file[Rc] = reg_file[Ra] * literal;
  PC += 1;
}

void OR(void)
{
  reg_file[Rc] = reg_file[Ra] | reg_file[Rb];
  PC += 1;
}

void ORC(void)
{
  reg_file[Rc] = reg_file[Ra] | literal;
  PC += 1;
}

void SHL(void)
{
  reg_file[Rc] = reg_file[Ra] << reg_file[Rb];
  PC += 1;
}

void SHLC(void)
{
  reg_file[Rc] = reg_file[Ra] << (literal & 0x1f);
  PC += 1;
}

void SHR(void)
{
  reg_file[Rc] = reg_file[Ra] >> reg_file[Rb];
  PC += 1;
}

void SHRC(void)
{
  reg_file[Rc] = reg_file[Ra] >> (literal & 0x1f);
  PC += 1;
}

void SRA(void)
{ // Get Exact difference from above func.
  // Propagating sign bits to left (how to do it)
  reg_file[Rc] = reg_file[Ra] >> reg_file[Rb];
  PC += 1;
}

void SRAC(void)
{
  reg_file[Rc] = reg_file[Ra] >> (literal & 0x1f);
  PC += 1;
}

void ST(void)
{
  PC += 1;
  data_mem[reg_file[Ra] + literal] = reg_file[Rc];
}

void SUB(void)
{
  reg_file[Rc] = reg_file[Ra] - reg_file[Rb];
  PC += 1;
}

void SUBC(void)
{
  reg_file[Rc] = reg_file[Ra] - literal;
  PC += 1;
}

void XOR(void)
{
  reg_file[Rc] = reg_file[Ra] ^ reg_file[Rb];
  PC += 1;
}

void XORC(void)
{
  reg_file[Rc] = reg_file[Ra] ^ literal;
  PC += 1;
}

void NOP(void)
{
  // Place holder
}