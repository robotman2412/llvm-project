
namespace Pixie16 {

enum Regno {
	R0, R1, R2, R3, ST, PF, PC, Imm
};

extern const char *regNames[8];

enum Opcodes {
	ADD, SUB, INC, DEC
};

// Type used for opcodes.
typedef enum {
	ADD     = 000, SUB,     CMP,     AND,     OR,     XOR,
	ADDC    = 010, SUBC,    CMPC,    ANDC,    ORC,    XORC,
	INC     = 020, DEC,     CMP1,                             SHL  = 026, SHR,
	INCC    = 020, DECC,    CMP1C,                            SHLC = 026, SHRC,
	MOV_ULT = 040, MOV_UGT, MOV_SLT, MOV_SGT, MOV_EQ, MOV_CS, MOV,
	MOV_UGE = 050, MOV_ULE, MOV_SGE, MOV_SLE, MOV_NE, MOV_CC, MOV_JSR,    MOV_CX,
	LEA_ULT = 060, LEA_UGT, LEA_SLT, LEA_SGT, LEA_EQ, LEA_CS, LEA,
	LEA_UGE = 070, LEA_ULE, LEA_SGE, LEA_SLE, LEA_NE, LEA_CC, LEA_JSR,
} px_opcode_t;


}
