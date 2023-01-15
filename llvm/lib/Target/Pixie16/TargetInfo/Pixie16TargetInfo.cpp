
#include "Pixie16TargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

namespace llvm {

Target &getThePixie16Target() {
	static Target t;
	return t;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializePixie16TargetInfo() {
	RegisterTarget X(getThePixie16Target(), "Pixie16", "Pixie16", "Pixie16");
}

}
