//===-- Pixie16TargetInfo.cpp - Pixie16 Target Implementation -------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "TargetInfo/Pixie16TargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getThePixie16Target() {
  static Target ThePixie16Target;
  return ThePixie16Target;
}


extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializePixie16TargetInfo() {
  RegisterTarget<Triple::UnknownArch, /*HasJIT=*/false> X(
      getThePixie16Target(), "Pixie16", "Pixie16", "Pixie16");
}
