//===-- Pixie16MCAsmInfo.cpp - Pixie16 Asm properties -------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the declarations of the Pixie16MCAsmInfo properties.
//
//===----------------------------------------------------------------------===//

#include "Pixie16MCAsmInfo.h"
// #include "MCTargetDesc/Pixie16MCExpr.h"
#include "llvm/ADT/Triple.h"
#include "llvm/BinaryFormat/Dwarf.h"
#include "llvm/MC/MCStreamer.h"
using namespace llvm;

void Pixie16MCAsmInfo::anchor() {}

Pixie16MCAsmInfo::Pixie16MCAsmInfo(const Triple &TT) {
  CodePointerSize = CalleeSaveStackSlotSize = 1;
  MaxInstLength = 3;
  MinInstAlignment = 1;
  CommentString = "//";
  AlignmentIsInBytes = false;
  SupportsDebugInformation = true;
  ExceptionsType = ExceptionHandling::None;
  Data16bitsDirective = "\t.word\t";
  Data32bitsDirective = "\t.dword\t";
}

const MCExpr *Pixie16MCAsmInfo::getExprForFDESymbol(const MCSymbol *Sym,
                                                  unsigned Encoding,
                                                  MCStreamer &Streamer) const {
//   if (!(Encoding & dwarf::DW_EH_PE_pcrel))
//     return MCAsmInfo::getExprForFDESymbol(Sym, Encoding, Streamer);

//   // The default symbol subtraction results in an ADD/SUB relocation pair.
//   // Processing this relocation pair is problematic when linker relaxation is
//   // enabled, so we follow binutils in using the R_Pixie16_32_PCREL relocation
//   // for the FDE initial location.
//   MCContext &Ctx = Streamer.getContext();
//   const MCExpr *ME =
//       MCSymbolRefExpr::create(Sym, MCSymbolRefExpr::VK_None, Ctx);
//   assert(Encoding & dwarf::DW_EH_PE_sdata4 && "Unexpected encoding");
//   return Pixie16MCExpr::create(ME, Pixie16MCExpr::VK_Pixie16_32_PCREL, Ctx);
}
