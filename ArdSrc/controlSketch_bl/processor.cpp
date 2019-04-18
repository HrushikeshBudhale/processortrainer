
#include "processor.h"
#include "BluetoothSerial.h"
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
extern BluetoothSerial SerialBT;
extern boolean doneUpload; // ! External variable
unsigned long int cntlOp;
boolean isTypeSTR = false; // Required because only STORE sends memory addr.
String outString;          // a String to hold outgoing data

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
// ! for testing only
void printMems(void)
{
    SerialBT.println("Register file: @@@@@@@@@@@");
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            SerialBT.print("\t");
            SerialBT.print(reg_file[i + (j * 8)]);
        }
        SerialBT.println();
    }
    SerialBT.println("Data memory: @@@@@@@@@@@");
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            SerialBT.print("\t");
            SerialBT.print(data_mem[i + (j * 5)]);
        }
        SerialBT.println();
    }
}

void evaluate(void)
{
    if (doneUpload)
    {
        fetch();
        decode();
        execute();
        sendTx();
    }
    // SerialBT.println("====================================================");
}

void fetch(void)
{
    // SerialBT.println("In fetch");
    opcode = (prog_data[PC] >> 26);      // bits 31 - 26
    Rc = ((prog_data[PC] >> 21) & 0x1f); // bits 25 - 21
    Ra = ((prog_data[PC] >> 16) & 0x1f); // bits 20 - 16
    Rb = ((prog_data[PC] >> 11) & 0x1f); // bits 15 - 11
    literal = (prog_data[PC] & 0xffff);  // bits 15 - 0
    // SerialBT.print("opcode= ");
    // SerialBT.print(opcode);
    // SerialBT.print(", Rc= ");
    // SerialBT.print(Rc);
    // SerialBT.print(", Ra= ");
    // SerialBT.print(Ra);
    // SerialBT.print(", Rb= ");
    // SerialBT.print(Rb);
    // SerialBT.print(", literal= ");
    // SerialBT.println(literal);
}

void decode(void)
{
    // SerialBT.println("In decode");
    isTypeSTR = false;
    char code = opcode - 24;
    if (code > 7 && code < 24)
    {
        // OP
        // SerialBT.println("cntl type OP");
        cntlOp = ((opcode << ALUFN) || (1 << WERF) || (1 << WDSEL));
    }
    else if (code > 23 && code < 40)
    {
        // OPC
        // SerialBT.println("cntl type OPC");
        cntlOp = ((opcode << ALUFN) || (1 << WERF) || (1 << BSEL) || (1 << WDSEL));
    }
    else
    {
        switch (code)
        {
        case 0:
            // LD
            // SerialBT.println("cntl type LD");
            cntlOp = ((8 << ALUFN) || (1 << WERF) || (1 << BSEL) || (2 << WDSEL));
            break;
        case 1:
            // ST
            isTypeSTR = true;
            // SerialBT.println("cntl type ST");
            cntlOp = ((8 << ALUFN) || (1 << BSEL) || (1 << WR) || (1 << RA2SEL));
            break;
        case 3:
            // JMP
            // SerialBT.println("cntl type JMP");
            cntlOp = ((1 << WERF) || (2 << PCSEL));
            break;
        case 5:
            // BEQ
            // SerialBT.println("cntl type BEQ");
            if (z)
                cntlOp = ((1 << WERF) || (1 << PCSEL));
            else
                cntlOp = ((1 << WERF) || (0 << PCSEL));
            break;
        case 6:
            // BNE
            // SerialBT.println("cntl type BNE");
            if (z)
                cntlOp = ((1 << WERF) || (0 << PCSEL));
            else
                cntlOp = ((1 << WERF) || (1 << PCSEL));
            break;
        case 7:
            // LDR
            // SerialBT.println("cntl type LDR");
            cntlOp = ((1 << WERF) || (2 << WDSEL) || (1 << ASEL));
            break;
        default:
            // Illop
            // SerialBT.println("cntl type Illop");
            cntlOp = ((1 << WERF) || (4 << PCSEL) || (1 << WASEL));
            break;
        }
    }
}

void execute(void)
{
    // SerialBT.println("In execute");
    funcLookupTbl[opcode - 24](); // opcode starts from 24
}

void sendTx(void)
{
    outString = String(PC) + " ";
    if (isTypeSTR)
    {
        outString += ": " + String(reg_file[Ra] + literal);
        outString += ":" + String(reg_file[Rc]);
    }
    else
    {
        outString += String(Rc) + ":";
        outString += String(reg_file[Rc]) + " :";
    }
    SerialBT.println(outString);
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
    // SerialBT.println("Executing ADD");
    reg_file[Rc] = (unsigned int)(reg_file[Ra] + reg_file[Rb]);
    PC += 1;
}

void ADDC(void)
{
    // SerialBT.println("Executing ADDC");
    reg_file[Rc] = reg_file[Ra] + literal;
    PC += 1;
}

void AND(void)
{
    // SerialBT.println("Executing AND");
    reg_file[Rc] = reg_file[Ra] & reg_file[Rb];
    PC += 1;
}

void ANDC(void)
{
    // SerialBT.println("Executing ANDC");
    reg_file[Rc] = reg_file[Ra] & literal;
    PC += 1;
}

void BEQ(void)
{
    // SerialBT.println("Executing BEQ");
    PC += 1;
    reg_file[Rc] = PC;
    if (reg_file[Ra] == 0)
        PC += literal;
}

void BNE(void)
{
    // SerialBT.println("Executing BNE");
    PC += 1;
    reg_file[Rc] = PC;
    if (reg_file[Ra] != 0)
        PC += literal;
}

void CMPEQ(void)
{
    // SerialBT.println("Executing CMPEQ");
    PC += 1;
    if (reg_file[Ra] == reg_file[Rb])
        reg_file[Rc] = 1;
    else
        reg_file[Rc] = 0;
}

void CMPEQC(void)
{
    // SerialBT.println("Executing CMPEQC");
    PC += 1;
    if (reg_file[Ra] == literal)
        reg_file[Rc] = 1;
    else
        reg_file[Rc] = 0;
}

void CMPLE(void)
{
    // SerialBT.println("Executing CMPLE");
    PC += 1;
    if (reg_file[Ra] <= reg_file[Rb])
        reg_file[Rc] = 1;
    else
        reg_file[Rc] = 0;
}

void CMPLEC(void)
{
    // SerialBT.println("Executing CMPLEC");
    PC += 1;
    if (reg_file[Ra] <= literal)
        reg_file[Rc] = 1;
    else
        reg_file[Rc] = 0;
}

void CMPLT(void)
{
    // SerialBT.println("Executing CMPLT");
    PC += 1;
    if (reg_file[Ra] < reg_file[Rb])
        reg_file[Rc] = 1;
    else
        reg_file[Rc] = 0;
}

void CMPLTC(void)
{
    // SerialBT.println("Executing CMPLTC");
    PC += 1;
    if (reg_file[Ra] < literal)
        reg_file[Rc] = 1;
    else
        reg_file[Rc] = 0;
}

void DIV(void)
{
    // SerialBT.println("Executing DIV");
    reg_file[Rc] = reg_file[Ra] / reg_file[Rb];
    PC += 1;
}

void DIVC(void)
{
    // SerialBT.println("Executing DIVC");
    reg_file[Rc] = reg_file[Ra] / literal;
    PC += 1;
}

void JMP(void)
{
    // SerialBT.println("Executing JMP");
    PC += 1;
    reg_file[Rc] = PC;
    PC = reg_file[Ra] & 0xfffffffc;
}

void LD(void)
{
    // SerialBT.println("Executing LD");
    PC += 1;
    reg_file[Rc] = data_mem[reg_file[Ra] + literal];
}

void LDR(void)
{
    // SerialBT.println("Executing LDR");
    PC += 1;
    reg_file[Rc] = data_mem[PC + literal];
}

void MUL(void)
{
    // SerialBT.println("Executing MUL");
    reg_file[Rc] = reg_file[Ra] * reg_file[Rb];
    PC += 1;
}

void MULC(void)
{
    // SerialBT.println("Executing MULC");
    reg_file[Rc] = reg_file[Ra] * literal;
    PC += 1;
}

void OR(void)
{
    // SerialBT.println("Executing OR");
    reg_file[Rc] = reg_file[Ra] | reg_file[Rb];
    PC += 1;
}

void ORC(void)
{
    // SerialBT.println("Executing ORC");
    reg_file[Rc] = reg_file[Ra] | literal;
    PC += 1;
}

void SHL(void)
{
    // SerialBT.println("Executing SHL");
    reg_file[Rc] = reg_file[Ra] << reg_file[Rb];
    PC += 1;
}

void SHLC(void)
{
    // SerialBT.println("Executing SHLC");
    reg_file[Rc] = reg_file[Ra] << (literal & 0x1f);
    PC += 1;
}

void SHR(void)
{
    // SerialBT.println("Executing SHR");
    reg_file[Rc] = reg_file[Ra] >> reg_file[Rb];
    PC += 1;
}

void SHRC(void)
{
    // SerialBT.println("Executing SHRC");
    reg_file[Rc] = reg_file[Ra] >> (literal & 0x1f);
    PC += 1;
}

void SRA(void)
{ // Get Exact difference from above func.
    // Propagating sign bits to left (how to do it)
    // SerialBT.println("Executing SRA");
    reg_file[Rc] = reg_file[Ra] >> reg_file[Rb];
    PC += 1;
}

void SRAC(void)
{
    // SerialBT.println("Executing SRAC");
    reg_file[Rc] = reg_file[Ra] >> (literal & 0x1f);
    PC += 1;
}

void ST(void)
{
    // SerialBT.println("Executing ST");
    PC += 1;
    data_mem[reg_file[Ra] + literal] = reg_file[Rc];
}

void SUB(void)
{
    // SerialBT.println("Executing SUB");
    reg_file[Rc] = reg_file[Ra] - reg_file[Rb];
    PC += 1;
}

void SUBC(void)
{
    // SerialBT.println("Executing SUBC");
    reg_file[Rc] = reg_file[Ra] - literal;
    PC += 1;
}

void XOR(void)
{
    // SerialBT.println("Executing XOR");
    reg_file[Rc] = reg_file[Ra] ^ reg_file[Rb];
    PC += 1;
}

void XORC(void)
{
    // SerialBT.println("Executing XORC");
    reg_file[Rc] = reg_file[Ra] ^ literal;
    PC += 1;
}

void NOPE()
{
    // SerialBT.println("Executing NOPE");
    // Place holder
}

void initLookupTbl(void)
{
    // SerialBT.println("Lookup table initialised!");
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