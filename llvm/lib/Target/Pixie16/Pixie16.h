
#ifndef LLVM_LIB_TARGET_PIXIE16_PIXIE16_H
#define LLVM_LIB_TARGET_PIXIE16_PIXIE16_H

namespace Pixie16 {
	
// Math offsets for MATH category instructions.
enum MathOffsets {
	MATH_ADD, MATH_SUB, MATH_CMP, MATH_AND, MATH_OR, MATH_XOR, MATH_SHL, MATH_SHR
};

// Condition offsets for MOV and LEA category instructions.
enum CondOffsets {
	COND_ULT, COND_UGT, COND_SLT, COND_SGT, COND_EQ, COND_CS, COND_TRUE, COND_INVALID,
	COND_UGE, COND_ULE, COND_SGE, COND_SLE, COND_NE, COND_CC, COND_JSR,  COND_CX,
};

// PX16 registers enum.
enum Regs {
	R0, R1, R2, R3, ST, PF, PC
};

// PX16 instruction categories.
enum InstCategories {
	MASK_OPCODE   = 070,
	MASK_COND     = 007,
	
	OFFS_MATH2    = 000,
	OFFS_MATH1    = 020,
	OFFS_MATH2C   = 010,
	OFFS_MATH1C   = 030,
	
	MASK_MATH1    = 020,
	MASK_MATHC    = 010,
	
	OFFS_MOV      = 040,
	OFFS_LEA      = 060,
	
	MASK_LEA      = 020,
	MASK_INV_COND = 010,
};

static inline bool isMath1(unsigned insn) {
	return (insn & MASK_OPCODE & ~MASK_MATHC) == OFFS_MATH1;
}

static inline bool isMath2(unsigned insn) {
	return (insn & MASK_OPCODE & ~MASK_MATHC) == OFFS_MATH2;
}

static inline bool isMov(unsigned insn) {
	return (insn & MASK_OPCODE & ~MASK_INV_COND) == OFFS_MOV;
}

static inline bool isLea(unsigned insn) {
	return (insn & MASK_OPCODE & ~MASK_INV_COND) == OFFS_LEA;
}

}

#endif // LLVM_LIB_TARGET_PIXIE16_PIXIE16_H
