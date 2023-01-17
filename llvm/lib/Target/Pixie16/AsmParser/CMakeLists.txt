add_llvm_component_library(LLVMPixie16AsmParser
  Pixie16AsmParser.cpp

  LINK_COMPONENTS
  MC
  MCParser
#   Pixie16Desc
#   Pixie16Info
  Support
  TargetParser

  ADD_TO_COMPONENT
  Pixie16
  )
