#!/usr/bin/env python
import sys

if len(sys.argv) != 2:
    print("Usage llvm-lexer.py <ll file>")
    exit(1)

def replace_str(s):
    '''
    replace "..." by str
    '''
    res = ""
    flag = False
    escape = False
    for ch in s:
        if escape == True:
            # state B -> B
            escape = False
        if ch == '\"':
            if flag == False:
                # state A -> B
                flag = True
            else:
                # state B -> A
                flag = False
                res += " str"
        else:
            if flag == False:
                # state A -> A
                res += ch
            else:
                if ch == '\\':
                    # B -> B
                    escape = True
    return res


with open(sys.argv[1], "r") as f:
    for line in f:
        tokens = line.split()
        if len(tokens) == 0:
            continue
        if tokens[0] == ";":
            continue
        if tokens[0] == "target":
            continue
        line = replace_str(line)

        for token in line.split():
            print(token)

                


