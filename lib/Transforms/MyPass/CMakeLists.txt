#add_llvm_loadable_module( LLVMMyPass
#  MyPass.cpp
#
#  DEPENDS
#  intrinsics_gen
#  PLUGIN_TOOL
#  opt
#  )

add_llvm_library(LLVMMyPass
  MyPass.cpp
  )
add_dependencies(LLVMMyPass intrinsics_gen)
