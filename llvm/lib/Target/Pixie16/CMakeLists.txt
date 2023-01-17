add_llvm_component_group(Pixie16)

set(LLVM_TARGET_DEFINITIONS Pixie16.td)

tablegen(LLVM Pixie16GenAsmMatcher.inc -gen-asm-matcher)
# tablegen(LLVM Pixie16GenAsmWriter.inc -gen-asm-writer)
# tablegen(LLVM Pixie16GenCallingConv.inc -gen-callingconv)
# tablegen(LLVM Pixie16GenDAGISel.inc -gen-dag-isel)
# tablegen(LLVM Pixie16GenDisassemblerTables.inc -gen-disassembler)
# tablegen(LLVM Pixie16GenFastISel.inc -gen-fast-isel)
# tablegen(LLVM Pixie16GenGlobalISel.inc -gen-global-isel)
# tablegen(LLVM Pixie16GenPostLegalizeGICombiner.inc -gen-global-isel-combiner
#               -combiners="Pixie16PostLegalizerCombinerHelper")
tablegen(LLVM Pixie16GenInstrInfo.inc -gen-instr-info)
# tablegen(LLVM Pixie16GenMCCodeEmitter.inc -gen-emitter)
# tablegen(LLVM Pixie16GenMCPseudoLowering.inc -gen-pseudo-lowering)
# tablegen(LLVM Pixie16GenRegisterBank.inc -gen-register-bank)
tablegen(LLVM Pixie16GenRegisterInfo.inc -gen-register-info)
# tablegen(LLVM Pixie16GenSubtargetInfo.inc -gen-subtarget)
# tablegen(LLVM Pixie16GenExegesis.inc -gen-exegesis)

add_public_tablegen_target(Pixie16CommonTableGen)

add_llvm_target(Pixie16CodeGen
  # Pixie16TargetMachine.cpp
  # Pixie16InstPrinter.cpp

  LINK_COMPONENTS
  Analysis
  AsmPrinter
  CodeGen
  Core
  MC
  Pixie16Desc
  Pixie16Info
  SelectionDAG
  Support
  Target
  TargetParser
  GlobalISel

  ADD_TO_COMPONENT
  Pixie16
  )

add_subdirectory(AsmParser)
# add_subdirectory(Disassembler)
add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
