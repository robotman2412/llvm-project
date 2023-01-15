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

class Pixie16Reg<bits<3> Enc, string c>: Register<n> {
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

def GRRegs : RegisterClass<"Pixie16", [i16], 16, (sequence "R%i",0,3)>;
def SPRegs : RegisterClass<"Pixie16", [i16], 16, [ST, PF, PC]>;

//===----------------------------------------------------------------------===//
// Calling conventions
//===----------------------------------------------------------------------===//

def CC_Pixie16_Regs: CallingConv<[
	CCAssignToReg<[R0, R1, R2, R3]>
]>;

def CC_Pixie16_Stack: CallingConv<[
	CCAssignToStack<0, 0>
]>;

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

class InstPixie16<string asmstr>: Instruction {
	let AsmString = asmstr;
}

def MOVrr: InstPixie16<(outs GRRegs:$a), (ins i16imm:$b), "MOV $a, $b", [(set i16:$a, i16imm:$b)]>;
def ADD: InstPixie16<(outs GRRegs:$a), (ins GRRegs:$b), "ADD $a, $b", [(set i16:$a, (add i16:$a, i16:$b))]>;
