
#include "Pixie16TargetMachine.h"
#include "TargetInfo/Pixie16TargetInfo.h"

#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/MC/TargetRegistry.h"

namespace llvm {

static TargetOptions getTargetOptions() {
	TargetOptions opts;
	
	
	
	return opts;
}

Pixie16TargetMachine::Pixie16TargetMachine(
	const Target &T, const Triple &TT,
	StringRef &CPU, StringRef &FS,
	const TargetOptions &Options,
	std::optional<Reloc::Model> &RM,
	std::optional<CodeModel::Model> &CM,
	CodeGenOpt::Level &OL, bool &JIT)
	
	: LLVMTargetMachine(
		T, "e-p:16:16-i:16:16",
		TT, CPU, FS, Options,
		RM.value_or(Reloc::PIC_),
		CM.value_or(CodeModel::Tiny),
		OL) {
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializePixie16Target() {
	// Register the target.
	RegisterTargetMachine<Pixie16TargetMachine> X(getThePixie16Target());
	
	PassRegistry &PR = *PassRegistry::getPassRegistry();
	// initializePixie16DAGToDAGISelPass(PR);
}

}
