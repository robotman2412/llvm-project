
#include "llvm/Target/TargetMachine.h"
#include "llvm/CodeGen/TargetInstrInfo.h"
#include "llvm/CodeGen/TargetRegisterInfo.h"

namespace llvm {

class Module;


class Pixie16TargetMachine: public LLVMTargetMachine {
	// const DataLayout dataLayout; // Calculates type size & alignment
	// SparcSubtarget Subtarget;
	// SparcInstrInfo InstrInfo;
	// TargetFrameInfo FrameInfo;

protected:
	// virtual const TargetAsmInfo *createTargetAsmInfo() const;

public:
	Pixie16TargetMachine(const Target&, const Triple&, StringRef&, StringRef&, const TargetOptions&, std::optional<Reloc::Model>&, std::optional<CodeModel::Model>&, CodeGenOpt::Level&, bool&);
	
	// virtual const Pixie16InstrInfo *getInstrInfo() const {return &InstrInfo; }
	// virtual const TargetFrameInfo *getFrameInfo() const {return &FrameInfo; }
	// virtual const TargetSubtarget *getSubtargetImpl() const{return &Subtarget; }
	// virtual const TargetRegisterInfo *getRegisterInfo() const {return &InstrInfo.getRegisterInfo();}
	// virtual const DataLayout *getDataLayout() const { return &dataLayout; }
	// static unsigned getModuleMatchQuality(const Module &M);
	
	// // Pass Pipeline Configuration
	// virtual bool addInstSelector(PassManagerBase &PM, bool Fast);
	// virtual bool addPreEmitPass(PassManagerBase &PM, bool Fast);
};

}
