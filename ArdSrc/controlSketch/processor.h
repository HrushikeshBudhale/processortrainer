
#ifndef _processor_
#define _processor_

#define REG_LEN 32  // register file size
#define PROG_LEN 20 // Program memory size
#define MEM_LEN 20  // data memory size

// Process related functions
void initLookupTbl(void);
void evaluate(void);
void fetch(void);
void decode(void);
void execute(void);
void reset(void);

// Process functions
void ADD(void);
void ADDC(void);
void AND(void);
void ANDC(void);
void BEQ(void);
void BNE(void);
void CMPEQ(void);
void CMPEQC(void);
void CMPLE(void);
void CMPLEC(void);
void CMPLT(void);
void CMPLTC(void);
void DIV(void);
void DIVC(void);
void JMP(void);
void LD(void);
void LDR(void);
void MUL(void);
void MULC(void);
void OR(void);
void ORC(void);
void SHL(void);
void SHLC(void);
void SHR(void);
void SHRC(void);
void SRA(void);
void SRAC(void);
void ST(void);
void SUB(void);
void SUBC(void);
void XOR(void);
void XORC(void);
void NOPE();

#endif