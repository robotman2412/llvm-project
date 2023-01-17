//===-- Pixie16.td - Describe the Pixie16 Target Machine ---------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// This is the top level entry point for the Pixie16 target.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Target-independent interfaces
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// Register File
//===----------------------------------------------------------------------===//

class Pixie16Reg<bits<16> Enc, string n>: Register<n> {
	let HWEncoding = Enc;
	let Namespace  = "Pixie16";
}

def R0: Pixie16Reg<0, "R0">;
def R1: Pixie16Reg<1, "R1">;
def R2: Pixie16Reg<2, "R2">;
def R3: Pixie16Reg<3, "R3">;
def ST: Pixie16Reg<4, "ST">;
def PF: Pixie16Reg<5, "PF">;
def PC: Pixie16Reg<6, "PC">;

def GPRegs : RegisterClass<"Pixie16", [i16], 16, (add (sequence "R%i",0,3), ST, PF, PC)>;
// def SPRegs : RegisterClass<"Pixie16", [i16], 16, (add ST, PF, PC)>;

//===----------------------------------------------------------------------===//
// Calling conventions
//===----------------------------------------------------------------------===//

// def CC_Pixie16_Regs: CallingConv<[
// 	CCAssignToReg<[R0, R1, R2, R3]>
// ]>;

// def CC_Pixie16_Stack: CallingConv<[
// 	CCAssignToStack<0, 0>
// ]>;

//===----------------------------------------------------------------------===//
// Immediates
//===----------------------------------------------------------------------===//

class ImmAsmOperand<int width>: AsmOperandClass {
	let Name = "Imm" # width;
	let RenderMethod = "addImmOperands";
	let DiagnosticType = !strconcat("Invalid", Name);
}

def imm16: Operand<i16> {
	let ParserMatchClass = ImmAsmOperand<16>;
	let EncoderMethod = "getImmOpValue";
	let DecoderMethod = "decodeImmOperand<12>";
}

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

class InstPixie16<string asmstr, dag outs, dag ins, bits<1> y, bits<3> x, bits<6> o>: Instruction {
	bits<16> Inst;
	bits<16> SoftFail = 0;
	let Size = 1;
	
	bits<3> b;
	bits<3> a;
	
	let Inst{15}    = y;
	let Inst{14-12} = x;
	let Inst{11-9}  = b;
	let Inst{8-6}   = a;
	let Inst{5-0}   = o;
	
	dag OutOperandList = outs;
	dag InOperandList = ins;
	let AsmString = asmstr;
	let Namespace = "Pixie16";
	
	let hasSideEffects = 0;
	let mayLoad = 0;
	let mayStore = 0;
}

// Single-parameter instructions (MATH1).
class InstPixie16_R<string asmstr, dag outs, dag ins, bits<3> x, bits<6> o>
		: InstPixie16<asmstr, outs, ins, 0, x, o>;

// Dual-parameter instructions (everything else).
class InstPixie16_RR<string asmstr, dag outs, dag ins, bits<1> y, bits<3> x, bits<6> o>
		: InstPixie16<asmstr, outs, ins, y, x, o>;

def MOVrr: InstPixie16_RR<"MOV $a, $b", (outs GPRegs:$a), (ins GPRegs:$b), 1, 7, 046>;
def MOVri: InstPixie16_RR<"MOV $a, $b", (outs GPRegs:$a), (ins imm16:$b), 1, 7, 046>;

//===----------------------------------------------------------------------===//
// Define the Pixie16 target.
//===----------------------------------------------------------------------===//

def Pixie16InstrInfo : InstrInfo {
  let guessInstructionProperties = 0;
}

def Pixie16AsmParser : AsmParser {
  let ShouldEmitMatchRegisterAltName = 1;
  let AllowDuplicateRegisterNames = 1;
}

// def Pixie16AsmWriter : AsmWriter {
//   int PassSubtarget = 1;
// }

def Pixie16 : Target {
  let InstructionSet = Pixie16InstrInfo;
  let AssemblyParsers = [Pixie16AsmParser];
  let AssemblyWriters = [/*Pixie16AsmWriter*/];
  let AllowRegisterRenaming = 0;
}