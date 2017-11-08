#include "MyAsmWriter.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Instruction.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

#define DEBUG_TYPE "hello"

STATISTIC(HelloCounter, "Counts number of functions greeted");

namespace {
  // Hello - The first implementation, without getAnalysisUsage.
  struct LLVMLexer : public ModulePass {
    static char ID; // Pass identification, replacement for typeid
    LLVMLexer() : ModulePass(ID) {}

    bool runOnModule(Module &M) override {
      ++HelloCounter;
      M.print(errs(), nullptr, false, false);
      return false;
    }
  };
}

char LLVMLexer::ID = 0;
static RegisterPass<LLVMLexer> X("llvm-lexer", "LLVM Lexer Pass: print tokens of IR");

