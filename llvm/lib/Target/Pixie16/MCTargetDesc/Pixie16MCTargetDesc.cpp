
#include "Pixie16MCTargetDesc.h"
#include "Pixie16InstPrinter.h"
// #include "Pixie16MCAsmInfo.h"
// #include "Pixie16TargetStreamer.h"
#include "TargetInfo/Pixie16TargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

namespace llvm {

static MCAsmInfo *createPixie16MCAsmInfo(const MCRegisterInfo &MRI,
                                       const Triple &TT,
                                       const MCTargetOptions &Options) {
//   MCAsmInfo *MAI = new Pixie16ELFMCAsmInfo(TT);
//   unsigned Reg = MRI.getDwarfRegNum(SP::O6, true);
//   MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, Reg, 0);
//   MAI->addInitialFrameState(Inst);
//   return MAI;
}

static MCAsmInfo *createPixie16V9MCAsmInfo(const MCRegisterInfo &MRI,
                                         const Triple &TT,
                                         const MCTargetOptions &Options) {
//   MCAsmInfo *MAI = new Pixie16ELFMCAsmInfo(TT);
//   unsigned Reg = MRI.getDwarfRegNum(SP::O6, true);
//   MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, Reg, 2047);
//   MAI->addInitialFrameState(Inst);
//   return MAI;
}

static MCInstrInfo *createPixie16MCInstrInfo() {
//   MCInstrInfo *X = new MCInstrInfo();
//   InitPixie16MCInstrInfo(X);
//   return X;
}

static MCRegisterInfo *createPixie16MCRegisterInfo(const Triple &TT) {
//   MCRegisterInfo *X = new MCRegisterInfo();
//   InitPixie16MCRegisterInfo(X, SP::O7);
//   return X;
}

static MCSubtargetInfo *
createPixie16MCSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS) {
  if (CPU.empty()) CPU = "Pixie16";
//   return createPixie16MCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCTargetStreamer *
createObjectTargetStreamer(MCStreamer &S, const MCSubtargetInfo &STI) {
//   return new Pixie16TargetELFStreamer(S);
}

static MCTargetStreamer *createTargetAsmStreamer(MCStreamer &S,
                                                 formatted_raw_ostream &OS,
                                                 MCInstPrinter *InstPrint,
                                                 bool isVerboseAsm) {
//   return new Pixie16TargetAsmStreamer(S, OS);
}

static MCTargetStreamer *createNullTargetStreamer(MCStreamer &S) {
//   return new Pixie16TargetStreamer(S);
}

static MCInstPrinter *createPixie16MCInstPrinter(const Triple &T,
                                               unsigned SyntaxVariant,
                                               const MCAsmInfo &MAI,
                                               const MCInstrInfo &MII,
                                               const MCRegisterInfo &MRI) {
  return new Pixie16InstPrinter(MAI, MII, MRI);
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializePixie16TargetMC() {
	Target &target = getThePixie16Target();
	
	// Register the MC asm info.
	RegisterMCAsmInfoFn X(target, createPixie16MCAsmInfo);
	
	// Register the MC instruction info.
	TargetRegistry::RegisterMCInstrInfo(target, createPixie16MCInstrInfo);
	
	// Register the MC register info.
	TargetRegistry::RegisterMCRegInfo(target, createPixie16MCRegisterInfo);
	
	// Register the MC subtarget info.
	TargetRegistry::RegisterMCSubtargetInfo(target, createPixie16MCSubtargetInfo);
	
	// Register the MC Code Emitter.
	TargetRegistry::RegisterMCCodeEmitter(target, createPixie16MCCodeEmitter);
	
	// Register the asm backend.
	TargetRegistry::RegisterMCAsmBackend(target, createPixie16AsmBackend);
	
	// Register the object target streamer.
	TargetRegistry::RegisterObjectTargetStreamer(target, createObjectTargetStreamer);
	
	// Register the asm streamer.
	TargetRegistry::RegisterAsmTargetStreamer(target, createTargetAsmStreamer);
	
	// Register the null streamer.
	TargetRegistry::RegisterNullTargetStreamer(target, createNullTargetStreamer);
	
	// Register the MCInstPrinter
	TargetRegistry::RegisterMCInstPrinter(target, createPixie16MCInstPrinter);
}

}
