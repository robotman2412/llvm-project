//===-- Pixie16MCTargetDesc.h - Pixie16 Target Descriptions -----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file provides Pixie16 specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_Pixie16_MCTARGETDESC_Pixie16MCTARGETDESC_H
#define LLVM_LIB_TARGET_Pixie16_MCTARGETDESC_Pixie16MCTARGETDESC_H

#include "llvm/Config/config.h"
#include "llvm/MC/MCTargetOptions.h"
#include "llvm/Support/DataTypes.h"
#include <memory>

namespace llvm {
class MCAsmBackend;
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class Target;

MCCodeEmitter *createPixie16MCCodeEmitter(const MCInstrInfo &MCII,
                                        MCContext &Ctx);

MCAsmBackend *createPixie16AsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                    const MCRegisterInfo &MRI,
                                    const MCTargetOptions &Options);

std::unique_ptr<MCObjectTargetWriter> createPixie16ELFObjectWriter(uint8_t OSABI,
                                                                 bool Is64Bit);
}

// Defines symbolic names for RISC-V registers.
#define GET_REGINFO_ENUM
#include "Pixie16GenRegisterInfo.inc"

// Defines symbolic names for RISC-V instructions.
#define GET_INSTRINFO_ENUM
#define GET_INSTRINFO_MC_HELPER_DECLS
#include "Pixie16GenInstrInfo.inc"

// #define GET_SUBTARGETINFO_ENUM
// #include "Pixie16GenSubtargetInfo.inc"

#endif
