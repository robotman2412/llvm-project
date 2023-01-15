//===-- Pixie16MCTargetDesc.h - Pixie16 Target Descriptions ---------*- C++ -*-===//
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

#ifndef LLVM_LIB_TARGET_PIXIE16_MCTARGETDESC_PIXIE16MCTARGETDESC_H
#define LLVM_LIB_TARGET_PIXIE16_MCTARGETDESC_PIXIE16MCTARGETDESC_H

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
class MCTargetOptions;
class Target;

MCCodeEmitter *createPixie16MCCodeEmitter(const MCInstrInfo &MCII,
                                        MCContext &Ctx);
MCAsmBackend *createPixie16AsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                    const MCRegisterInfo &MRI,
                                    const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter> createPixie16ELFObjectWriter(bool Is64Bit,
                                                                 uint8_t OSABI);
} // End llvm namespace

// // Defines symbolic names for Pixie16 registers.  This defines a mapping from
// // register name to register number.
// //
// #define GET_REGINFO_ENUM
// #include "Pixie16GenRegisterInfo.inc"

// // Defines symbolic names for the Pixie16 instructions.
// //
// #define GET_INSTRINFO_ENUM
// #define GET_INSTRINFO_MC_HELPER_DECLS
// #include "Pixie16GenInstrInfo.inc"

// #define GET_SUBTARGETINFO_ENUM
// #include "Pixie16GenSubtargetInfo.inc"

#endif
