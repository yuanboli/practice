#!/usr/bin/env bash
if [ $# -ne 1 ] ; then
    echo "Usage <bc file>"
    exit 0
fi

opt -load LLVMLexer/LLVMLexer.so -llvm-lexer < $1 > /dev/null
