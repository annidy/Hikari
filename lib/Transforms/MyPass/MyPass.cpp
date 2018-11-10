//===- Hello.cpp - Example code from "Writing an LLVM Pass" ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements two versions of the LLVM "Hello World" pass described
// in docs/WritingAnLLVMPass.html
//
//===----------------------------------------------------------------------===//

#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/MyPass/MyPass.h"
using namespace llvm;

#define DEBUG_TYPE "mypass"

STATISTIC(MyPassCounter, "Counts number of functions greeted");

namespace {
  // Hello - The first implementation, without getAnalysisUsage.
  struct MyPass : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    MyPass() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      ++MyPassCounter;
      errs() << "MyPass: ";
      errs().write_escaped(F.getName()) << '\n';
      return false;
    }
  };
}

char MyPass::ID = 0;
static RegisterPass<MyPass> X("-mypass", "Hello World Pass");
Pass *llvm::createSimplePass(bool flag) { return new MyPass(); }