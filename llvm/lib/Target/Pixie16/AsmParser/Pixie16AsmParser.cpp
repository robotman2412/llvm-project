//===-- Pixie16AsmParser.cpp - Parse Pixie 16 assembly to MCInst instructions --===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===---------------------------------------------------------------------------===//

// #include "MCTargetDesc/Pixie16AsmBackend.h"
// #include "MCTargetDesc/Pixie16BaseInfo.h"
// #include "MCTargetDesc/Pixie16InstPrinter.h"
// #include "MCTargetDesc/Pixie16MCExpr.h"
// #include "MCTargetDesc/Pixie16MCTargetDesc.h"
// #include "MCTargetDesc/Pixie16MatInt.h"
// #include "MCTargetDesc/Pixie16TargetStreamer.h"
#include "TargetInfo/Pixie16TargetInfo.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/SmallBitVector.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/MC/MCAssembler.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstBuilder.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCObjectFileInfo.h"
#include "llvm/MC/MCParser/MCAsmLexer.h"
#include "llvm/MC/MCParser/MCParsedAsmOperand.h"
#include "llvm/MC/MCParser/MCTargetAsmParser.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCValue.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/MathExtras.h"
// #include "llvm/Support/Pixie16Attributes.h"
// #include "llvm/Support/Pixie16ISAInfo.h"

using namespace llvm;

namespace {

struct Pixie16Operand;

class Pixie16AsmParser: public MCTargetAsmParser {
  
public:
  Pixie16AsmParser(const MCSubtargetInfo &STI, MCAsmParser &Parser,
                 const MCInstrInfo &MII, const MCTargetOptions &Options)
      : MCTargetAsmParser(Options, STI, MII) {
    setAvailableFeatures(ComputeAvailableFeatures(STI.getFeatureBits()));
    
    // const MCObjectFileInfo *MOFI = Parser.getContext().getObjectFileInfo();
    // ParserOptions.IsPicEnabled = MOFI->isPositionIndependent();
  }
  
  bool parseRegister(MCRegister &RegNo, SMLoc &StartLoc, SMLoc &EndLoc) override;
  
  OperandMatchResultTy tryParseRegister(MCRegister &RegNo, SMLoc &StartLoc,
                                        SMLoc &EndLoc) override;
  
  bool ParseInstruction(ParseInstructionInfo &Info, StringRef Name,
                        SMLoc NameLoc, OperandVector &Operands) override;
  
  bool ParseDirective(AsmToken DirectiveID) override;
  
  bool MatchAndEmitInstruction(SMLoc IDLoc, unsigned &Opcode,
                               OperandVector &Operands, MCStreamer &Out,
                               uint64_t &ErrorInfo,
                               bool MatchingInlineAsm) override;
  
// Auto-generated instruction matching functions
#define GET_ASSEMBLER_HEADER
#include "Pixie16GenAsmMatcher.inc"
  
};

struct Pixie16Operand: public MCParsedAsmOperand {
  
};

// Auto-generated instruction matching functions
#define GET_MATCHER_IMPLEMENTATION
#include "Pixie16GenAsmMatcher.inc"

// bool Pixie16AsmParser::parseRegister(MCRegister &RegNo, SMLoc &StartLoc, SMLoc &EndLoc) {
  
// }

// OperandMatchResultTy tryParseRegister(MCRegister &RegNo, SMLoc &StartLoc,
//                                       SMLoc &EndLoc) {
//   // lolol
// }

// bool Pixie16AsmParser::ParseInstruction(ParseInstructionInfo &Info, StringRef Name,
//                       SMLoc NameLoc, OperandVector &Operands) {
//   // lolol
// }

// bool Pixie16AsmParser::ParseDirective(AsmToken DirectiveID) {
//   // lolol
// }

// bool Pixie16AsmParser::MatchAndEmitInstruction(SMLoc IDLoc, unsigned &Opcode,
//                                       OperandVector &Operands, MCStreamer &Out,
//                                       uint64_t &ErrorInfo,
//                                       bool MatchingInlineAsm) {
//   // lolol
// }

// void Pixie16AsmParser::convertToMapAndConstraints(unsigned Kind,
//                                 const OperandVector &Operands) {
//   // lolol
// }

}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializePixie16AsmParser() {
  RegisterMCAsmParser<Pixie16AsmParser> X(getThePixie16Target());
}
