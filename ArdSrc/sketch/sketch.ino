// include max7219 library

#define EXT_CLK 1

#define MODEPIN 2
#define CLKPIN 1
#define FREQPIN 3


//############## Global variables ###############
// Data Containers
unsigned long int prog_data[20];    // 32 bit
unsigned long int reg_file[32];
unsigned long int data_mem[20];

// Address Containers
unsigned char PC = 0;   // 8 bit
unsigned char opcode = 0;
unsigned char Rc = 0;
unsigned char Ra = 0;
unsigned char Rb = 0;

unsigned int literal = 0;   // 16 bit

int clkDelay = 0;

void initLookupTbl(void);
int setClkDelay(void);
void evaluate(void);

// type-defination: 'funtionPrt' now can be used as type
typedef void (*fuctionPtr)(void);

// Declare an array of pointer to functions (i.e. lookup table)
fuctionPtr funcLookupTbl[40];   // Stores array of pointers to all functions

void setup() {

    // set up all display devices
    // set up all input switch and frequency control pot
    // set up uart comm.

    initLookupTbl();
    
}

void loop() {
    // Wait for code upload
    // Store code
    // If code upload successful
    //while not (software)reset
    if(digitalRead(MODEPIN) == EXT_CLK){  // If external clock input is selected
         if(digitalRead(CLKPIN) == HIGH){   // If clk button if pressed
            evaluate();
            while(digitalRead(CLKPIN) != LOW){  // Wait for user to release the button
                delay(100);
            }
         }
    }
    else{   // internal clock (periodic)
        while(digitalRead(MODEPIN) == EXT_CLK){
            evaluate();
            setClkDelay();
            delay(clkDelay);    // Use timer instead, or else it will stuck here!
        }
    }
}

int setClkDelay(void){
    int clkFreq;
    clkFreq = analogRead(FREQPIN);   // 0 - 1024
    clkFreq = map(clkFreq, 1, 1000);    // 1 - 1000 Verify this function 
    clkDelay = 10000/clkFreq;   // (10000 - 10) 10sec - 10milliSec
    return(clkDelay);
}

void evaluate(void){
    opcode = get_opcode();
    execute(opcode);
}

void execute(int code){
    code -= 24; // opcode starts from 24
    funcLookupTbl[code]();
}

int get_opcode(void){
    return(prog_data[PC] >> 26);   // bits 31 - 26
}

int get_Rc(void){
    return((prog_data[PC] >> 21) & 0x1f);   // bits 25 - 21
}

int get_Ra(void){
    return((prog_data[PC] >> 16) & 0x1f);   // bits 20 - 16
}

int get_Rb(void){
    return((prog_data[PC] >> 11) & 0x1f);   // bits 15 - 11
}

int get_literal(void){
    return(prog_data[PC] & 0xffff); // bits 15 - 0
}

void set_CAB(void){
    Rc = get_Rc();
    Ra = get_Ra();
    Rb = get_Rb();
}

void set_CAL(void){
    Rc = get_Rc();
    Ra = get_Ra();
    literal = get_literal();
}

void initLookupTbl(void){
    funcLookupTbl[0]  = LD;     funcLookupTbl[1]  = ST;     funcLookupTbl[0]  = NOP;    funcLookupTbl[0]  = JMP;
    funcLookupTbl[4]  = NOP;    funcLookupTbl[5]  = BEQ;    funcLookupTbl[6]  = BNE;    funcLookupTbl[7]  = LDR;
    funcLookupTbl[8]  = ADD;    funcLookupTbl[9]  = SUB;    funcLookupTbl[10] = MUL;    funcLookupTbl[11] = DIV;
    funcLookupTbl[12] = CMPEQ;  funcLookupTbl[13] = CMPLT;  funcLookupTbl[14] = CMPLE;  funcLookupTbl[15] = NOP;
    funcLookupTbl[16] = AND;    funcLookupTbl[17] = OR;     funcLookupTbl[18] = XOR;    funcLookupTbl[19] = NOP;
    funcLookupTbl[20] = SHL;    funcLookupTbl[21] = SHR;    funcLookupTbl[22] = SRA;    funcLookupTbl[23] = NOP;
    funcLookupTbl[24] = ADDC;   funcLookupTbl[25] = SUBC;   funcLookupTbl[26] = MULC;   funcLookupTbl[27] = DIVC;
    funcLookupTbl[28] = CMPEQC; funcLookupTbl[29] = CMPLTC; funcLookupTbl[30] = CMPLEC; funcLookupTbl[31] = NOP;
    funcLookupTbl[32] = ANDC;   funcLookupTbl[33] = ORC;    funcLookupTbl[34] = XORC;   funcLookupTbl[35] = NOP;
    funcLookupTbl[36] = SHLC;   funcLookupTbl[37] = SHRC;   funcLookupTbl[38] = SRAC;   funcLookupTbl[39] = NOP;  
}

void ADD(void){
    set_CAB();
    reg_file[Rc] = (unsigned int)(reg_file[Ra] + reg_file[Rb]); // Check what gives error and apply to rest
    PC += 1;
}

void ADDC(void){
    set_CAL();
    reg_file[Rc] = reg_file[Ra] + literal;
    PC += 1;
}

void AND(void){
    set_CAB();
    reg_file[Rc] = reg_file[Ra] & reg_file[Rb];
    PC += 1;
}

void ANDC(void){
    set_CAL();
    reg_file[Rc] = reg_file[Ra] & literal;
    PC += 1;
}

void BEQ(void){
    set_CAL();
    PC += 1;
    reg_file[Rc] = PC;
    if(reg_file[Ra] == 0)
        PC += literal;
}

void BNE(void){
    set_CAL();
    PC += 1;
    reg_file[Rc] = PC;
    if(reg_file[Ra] != 0)
        PC += literal;
}

void CMPEQ(void){
    set_CAB();
    PC += 1;
    if(reg_file[Ra] == reg_file[Rb])
        reg_file[Rc] = 1;
    else
        reg_file[Rc] = 0;
}

void CMPEQC(void){
    set_CAL();
    PC += 1;
    if(reg_file[Ra] == literal)
        reg_file[Rc] = 1;
    else
        reg_file[Rc] = 0;
}

void CMPLE(void){
    set_CAB();
    PC += 1;
    if(reg_file[Ra] <= reg_file[Rb])
        reg_file[Rc] = 1;
    else
        reg_file[Rc] = 0;
}

void CMPLEC(void){
    set_CAL();
    PC += 1;
    if(reg_file[Ra] <= literal)
        reg_file[Rc] = 1;
    else
        reg_file[Rc] = 0;
}

void CMPLT(void){
    set_CAB();
    PC += 1;
    if(reg_file[Ra] < reg_file[Rb])
        reg_file[Rc] = 1;
    else
        reg_file[Rc] = 0;
}

void CMPLTC(void){
    set_CAL();
    PC += 1;
    if(reg_file[Ra] < literal)
        reg_file[Rc] = 1;
    else
        reg_file[Rc] = 0;
}

void DIV(void){
    set_CAB();
    reg_file[Rc] = reg_file[Ra] / reg_file[Rb];
    PC += 1;
}

void DIVC(void){
    set_CAL();
    reg_file[Rc] = reg_file[Ra] / literal;
    PC += 1;
}

void JMP(void){
    set_CAL();
    PC += 1;
    reg_file[Rc] = PC;
    PC = reg_file[Ra] & 0xfffffffc;
}

void LD(void){
    set_CAL();
    PC += 1;
    reg_file[Rc] = data_mem[reg_file[Ra] + literal];
}

void LDR(void){
    set_CAL();
    PC += 1;
    reg_file[Rc] = data_mem[PC + literal];
}

void MUL(void){
    set_CAB();
    reg_file[Rc] = reg_file[Ra] * reg_file[Rb];
    PC += 1;
}

void MULC(void){
    set_CAL();
    reg_file[Rc] = reg_file[Ra] * literal;
    PC += 1;
}

void OR(void){
    set_CAB();
    reg_file[Rc] = reg_file[Ra] | reg_file[Rb];
    PC += 1;
}

void ORC(void){
    set_CAL();
    reg_file[Rc] = reg_file[Ra] | literal;
    PC += 1;
}

void SHL(void){
    set_CAB();
    reg_file[Rc] = reg_file[Ra] << reg_file[Rb];
    PC += 1;
}

void SHLC(void){
    set_CAL();
    reg_file[Rc] = reg_file[Ra] << (literal & 0x1f);
    PC += 1;
}

void SHR(void){
    set_CAB();
    reg_file[Rc] = reg_file[Ra] >> reg_file[Rb];
    PC += 1;
}

void SHRC(void){
    set_CAL();
    reg_file[Rc] = reg_file[Ra] >> (literal & 0x1f);
    PC += 1;
}

void SRA(void){ // Get Exact difference from above func.
    set_CAB();  // Propagating sign bits to left (how to do it)
    reg_file[Rc] = reg_file[Ra] >> reg_file[Rb];
    PC += 1;
}

void SRAC(void){
    set_CAL();
    reg_file[Rc] = reg_file[Ra] >> (literal & 0x1f);
    PC += 1;
}

void ST(void){
    set_CAL();
    PC += 1;
    data_mem[reg_file[Ra] + literal] = reg_file[Rc];
}

void SUB(void){
    set_CAB();
    reg_file[Rc] = reg_file[Ra] - reg_file[Rb];
    PC += 1;
}

void SUBC(void){
    set_CAL();
    reg_file[Rc] = reg_file[Ra] - literal;
    PC += 1;
}

void XOR(void){
    set_CAB();
    reg_file[Rc] = reg_file[Ra] ^ reg_file[Rb];
    PC += 1;
}

void XORC(void){
    set_CAL();
    reg_file[Rc] = reg_file[Ra] ^ literal;
    PC += 1;
}

void NOP(void){
    // Place holder
}
