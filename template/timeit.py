#!/usr/bin/env python3

import subprocess 

progs = ['dijkstra.out', 'dijkstra.py', 'dijkstra.jl']
for prog in progs:
    inputfile = open('edges.txt')
    subprocess.call(["./" + prog], stdin=inputfile)


