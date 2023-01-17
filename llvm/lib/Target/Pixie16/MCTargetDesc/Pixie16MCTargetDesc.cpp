//===-- Pixie16MCTargetDesc.cpp - Pixie16 Target Descriptions -----------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
/// This file provides Pixie16-specific target descriptions.
///
//===----------------------------------------------------------------------===//

#include "Pixie16MCTargetDesc.h"
// #include "Pixie16BaseInfo.h"
// #include "Pixie16ELFStreamer.h"
// #include "Pixie16InstPrinter.h"
#include "Pixie16MCAsmInfo.h"
// #include "Pixie16MCObjectFileInfo.h"
// #include "Pixie16TargetStreamer.h"
#include "TargetInfo/Pixie16TargetInfo.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCInstrAnalysis.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCObjectFileInfo.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

#define GET_INSTRINFO_MC_DESC
#define ENABLE_INSTR_PREDICATE_VERIFIER
#include "Pixie16GenInstrInfo.inc"

#define GET_REGINFO_MC_DESC
#include "Pixie16GenRegisterInfo.inc"

// #define GET_SUBTARGETINFO_MC_DESC
// #include "Pixie16GenSubtargetInfo.inc"

using namespace llvm;

static MCInstrInfo *createPixie16MCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitPixie16MCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createPixie16MCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitPixie16MCRegisterInfo(X, Pixie16::R0);
  return X;
}

static MCAsmInfo *createPixie16MCAsmInfo(const MCRegisterInfo &MRI,
                                       const Triple &TT,
                                       const MCTargetOptions &Options) {
  MCAsmInfo *MAI = new Pixie16MCAsmInfo(TT);
  
//   MCRegister SP = MRI.getDwarfRegNum(Pixie16::X2, true);
//   MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
//   MAI->addInitialFrameState(Inst);
  
  return MAI;
}

static MCObjectFileInfo *
createPixie16MCObjectFileInfo(MCContext &Ctx, bool PIC,
                            bool LargeCodeModel = false) {
//   MCObjectFileInfo *MOFI = new Pixie16MCObjectFileInfo();
//   MOFI->initMCObjectFileInfo(Ctx, PIC, LargeCodeModel);
//   return MOFI;
}

static MCSubtargetInfo *createPixie16MCSubtargetInfo(const Triple &TT,
                                                   StringRef CPU, StringRef FS) {
  if (CPU.empty() || CPU == "generic")
    CPU = "pixie16";

//   return createPixie16MCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCInstPrinter *createPixie16MCInstPrinter(const Triple &T,
                                               unsigned SyntaxVariant,
                                               const MCAsmInfo &MAI,
                                               const MCInstrInfo &MII,
                                               const MCRegisterInfo &MRI) {
//   return new Pixie16InstPrinter(MAI, MII, MRI);
}

static MCTargetStreamer *
createPixie16ObjectTargetStreamer(MCStreamer &S, const MCSubtargetInfo &STI) {
//   const Triple &TT = STI.getTargetTriple();
//   if (TT.isOSBinFormatELF())
//     return new Pixie16TargetELFStreamer(S, STI);
//   return nullptr;
}

static MCTargetStreamer *createPixie16AsmTargetStreamer(MCStreamer &S,
                                                      formatted_raw_ostream &OS,
                                                      MCInstPrinter *InstPrint,
                                                      bool isVerboseAsm) {
//   return new Pixie16TargetAsmStreamer(S, OS);
}

static MCTargetStreamer *createPixie16NullTargetStreamer(MCStreamer &S) {
//   return new Pixie16TargetStreamer(S);
}

namespace {

class Pixie16MCInstrAnalysis : public MCInstrAnalysis {
public:
  explicit Pixie16MCInstrAnalysis(const MCInstrInfo *Info)
      : MCInstrAnalysis(Info) {}

  bool evaluateBranch(const MCInst &Inst, uint64_t Addr, uint64_t Size,
                      uint64_t &Target) const override {
    // if (isConditionalBranch(Inst)) {
    //   int64_t Imm;
    //   if (Size == 2)
    //     Imm = Inst.getOperand(1).getImm();
    //   else
    //     Imm = Inst.getOperand(2).getImm();
    //   Target = Addr + Imm;
    //   return true;
    // }

    // if (Inst.getOpcode() == Pixie16::C_JAL || Inst.getOpcode() == Pixie16::C_J) {
    //   Target = Addr + Inst.getOperand(0).getImm();
    //   return true;
    // }

    // if (Inst.getOpcode() == Pixie16::JAL) {
    //   Target = Addr + Inst.getOperand(1).getImm();
    //   return true;
    // }

    // return false;
  }
};

} // end anonymous namespace

static MCInstrAnalysis *createPixie16InstrAnalysis(const MCInstrInfo *Info) {
  return new Pixie16MCInstrAnalysis(Info);
}

namespace {
MCStreamer *createPixie16ELFStreamer(const Triple &T, MCContext &Context,
                                   std::unique_ptr<MCAsmBackend> &&MAB,
                                   std::unique_ptr<MCObjectWriter> &&MOW,
                                   std::unique_ptr<MCCodeEmitter> &&MCE,
                                   bool RelaxAll) {
//   return createPixie16ELFStreamer(Context, std::move(MAB), std::move(MOW),
//                                 std::move(MCE), RelaxAll);
}
} // end anonymous namespace

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializePixie16TargetMC() {
  for (Target *T : {&getThePixie16Target()}) {
    TargetRegistry::RegisterMCAsmInfo(*T, createPixie16MCAsmInfo);
    // TargetRegistry::RegisterMCObjectFileInfo(*T, createPixie16MCObjectFileInfo);
    // TargetRegistry::RegisterMCInstrInfo(*T, createPixie16MCInstrInfo);
    TargetRegistry::RegisterMCRegInfo(*T, createPixie16MCRegisterInfo);
    // TargetRegistry::RegisterMCAsmBackend(*T, createPixie16AsmBackend);
    // TargetRegistry::RegisterMCCodeEmitter(*T, createPixie16MCCodeEmitter);
    // TargetRegistry::RegisterMCInstPrinter(*T, createPixie16MCInstPrinter);
    // TargetRegistry::RegisterMCSubtargetInfo(*T, createPixie16MCSubtargetInfo);
    // TargetRegistry::RegisterELFStreamer(*T, createPixie16ELFStreamer);
    // TargetRegistry::RegisterObjectTargetStreamer(
    //     *T, createPixie16ObjectTargetStreamer);
    // TargetRegistry::RegisterMCInstrAnalysis(*T, createPixie16InstrAnalysis);

    // // Register the asm target streamer.
    // TargetRegistry::RegisterAsmTargetStreamer(*T, createPixie16AsmTargetStreamer);
    // // Register the null target streamer.
    // TargetRegistry::RegisterNullTargetStreamer(*T,
    //                                            createPixie16NullTargetStreamer);
  }
}
