add_llvm_component_library(LLVMPixie16Desc
#   Pixie16AsmBackend.cpp
#   Pixie16ELFObjectWriter.cpp
#   Pixie16InstPrinter.cpp
#   Pixie16MCAsmInfo.cpp
#   Pixie16MCCodeEmitter.cpp
  Pixie16MCTargetDesc.cpp
#   Pixie16MCExpr.cpp
#   Pixie16TargetStreamer.cpp

  LINK_COMPONENTS
  MC
#   Pixie16Info
  Support
  TargetParser

  ADD_TO_COMPONENT
  Pixie16
  )
