
#include "processor.h"
#include <Arduino.h>

// TODO: Include z signal in processor

// ============================= constants ==============================

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

// ========================== Global variables ===========================

// State variables
extern boolean doneUpload; // ! External variable
unsigned long int cntlOp;

// Data Containers
unsigned long int prog_data[PROG_LEN]; // 32 bit
unsigned long int reg_file[REG_LEN];
unsigned long int data_mem[MEM_LEN];

// Address Containers
unsigned char PC = 0;     //
unsigned char opcode = 0; //
unsigned char Rc = 0;     // 8 bit
unsigned char Ra = 0;     //
unsigned char Rb = 0;     //
unsigned char z = 0;      //
unsigned int literal = 0; // 16 bit

// type-defination: 'funtionPrt' now can be used as type
typedef void (*fuctionPtr)(void);

// Declare an array of pointer to functions (i.e. lookup table)
fuctionPtr funcLookupTbl[40]; // Stores array of pointers to all functions

// ===================== Process realated functions ======================

void evaluate(void)
{
    if (doneUpload)
    {
        fetch();
        decode();
        execute();
    }
    Serial.println("====================================================");
}

void fetch(void)
{
    Serial.println("In fetch");
    opcode = (prog_data[PC] >> 26);      // bits 31 - 26
    Rc = ((prog_data[PC] >> 21) & 0x1f); // bits 25 - 21
    Ra = ((prog_data[PC] >> 16) & 0x1f); // bits 20 - 16
    Rb = ((prog_data[PC] >> 11) & 0x1f); // bits 15 - 11
    literal = (prog_data[PC] & 0xffff);  // bits 15 - 0
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

void reset(void)
{
    PC = 0; // Clear program counter
    for (int i = 0; i < REG_LEN; i++)
    {
        reg_file[i] = 0; // Clear register fie
    }
    for (int i = 0; i < REG_LEN; i++)
    {
        data_mem[i] = 0; // Clear data memory
    }
}

// ========================= Process functions ===========================

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