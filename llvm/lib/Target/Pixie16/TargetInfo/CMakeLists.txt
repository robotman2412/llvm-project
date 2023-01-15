add_llvm_component_library(LLVMPixie16Info
  Pixie16TargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Pixie16
  )
