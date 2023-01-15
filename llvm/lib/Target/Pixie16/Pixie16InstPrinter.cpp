//===-- Pixie16InstPrinter.cpp - Convert Pixie16 MCInst to assembly syntax ----===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class prints an Pixie16 MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "asm-printer"

#include "Pixie16.h"
#include "Pixie16InstPrinter.h"

#include "llvm/ADT/StringExtras.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

#include <iostream>
#include <format>

// #include "Pixie16GenAsmWriter.inc"

using namespace Pixie16;

const char *Pixie16::RegNames[7] = {"R0", "R1", "R2", "R3", "ST", "PF", "PC"};
const char *Pixie16::OpcodeNames[64] = {
	// MATH2 category.
	"ADD",     "SUB",     "CMP",     "AND",     "OR",     "XOR",     NULL,      NULL,
	"ADDC",    "SUBC",    "CMPC",    "ANDC",    "ORC",    "XORC",    NULL,      NULL,
	
	// MATH1 category.
	"INC",     "DEC",     "CMP",     NULL,      NULL,      NULL,     "SHL",     "SHR",
	"INCC",    "DECC",    "CMPC",    NULL,      NULL,      NULL,     "SHLC",    "SHRC",
	
	// MOV category.
	"MOV.ULT", "MOV.UGT", "MOV.SLT", "MOV.SGT", "MOV.EQ",  "MOV.CS", "MOV",     NULL,
	"MOV.UGE", "MOV.ULE", "MOV.SGE", "MOV.SLE", "MOV.NE",  "MOV.CC", "MOV.JSR", "MOV.CX",
	
	// LEA category.
	"MOV.ULT", "MOV.UGT", "MOV.SLT", "MOV.SGT", "MOV.EQ",  "MOV.CS", "MOV",     NULL,
	"MOV.UGE", "MOV.ULE", "MOV.SGE", "MOV.SLE", "MOV.NE",  "MOV.CC", "MOV.JSR", NULL,
};

namespace llvm {

#define COMMENT_STYLE "// "

const char *Pixie16InstPrinter::getRegisterName(unsigned regno) {
	if (regno > 6) return "??";
	else return RegNames[regno];
}
  
void printRegName(raw_ostream &OS, unsigned regno) {
	OS << Pixie16InstPrinter::getRegisterName(regno);
}

static void printParam(const MCOperand &operand, raw_ostream &OS, const MCAsmInfo &MAI) {
	if (operand.isImm()) {
		OS << std::format("0x%04x", (int) operand.getImm() & 0xffff);
	} else if (operand.isReg()) {
		OS << RegNames[operand.getReg()];
	} else if (operand.isExpr()) {
		operand.getExpr()->print(OS, &MAI);
	}
}

void Pixie16InstPrinter::printInst(
	const MCInst *MI, uint64_t Address, StringRef Annot,
	const MCSubtargetInfo &STI, raw_ostream &OS) {
	
	unsigned opcode = MI->getOpcode();
	
	if (!OpcodeNames[opcode]) {
		// Assert opcode validity.
		OS << MAI.getCommentString() << "Invalid opcode " << opcode;
		std::cerr << "Invalid opcode " << opcode << std::endl;
		return;
	}
	
	if (MI->getNumOperands() != 1 && isMath1(opcode)) {
		// Assert MATH1 parameter count.
		OS << MAI.getCommentString() << "Arg count for " << OpcodeNames[opcode] << " invalid: 1 expected, got " << MI->getNumOperands();
		std::cerr << "Arg count for " << OpcodeNames[opcode] << " invalid: 1 expected, got " << MI->getNumOperands() << std::endl;
		return;
		
	} else if (MI->getNumOperands() != 2 && !isMath1(opcode)) {
		// Assert normal operand count.
		OS << MAI.getCommentString() << "Arg count for " << OpcodeNames[opcode] << " invalid: 2 expected, got " << MI->getNumOperands();
		std::cerr << "Arg count for " << OpcodeNames[opcode] << " invalid: 2 expected, got " << MI->getNumOperands() << std::endl;
		return;
	}
	
	const MCOperand &parA = MI->getOperand(0);
	if (parA.isImm() || parA.isBareSymbolRef()) {
		// Assert param A is not a constant.
		OS << MAI.getCommentString() << "Arg A is a constant, this is not allowed.";
		std::cerr << "Arg A is a constant, this is not allowed." << std::endl;
		
	}
	
	// Print opcode.
	OS << "\t" << OpcodeNames[opcode] << " ";
	
	// Print PAR A.
	printParam(parA, OS, MAI);
	
	if (!isMath1(opcode)) {
		// Print PAR B.
		OS << " ";
		printParam(MI->getOperand(1), OS, MAI);
	}
	
}

}
