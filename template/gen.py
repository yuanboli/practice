#!/usr/bin/env python3
import sys
import random

if len(sys.argv) != 2:
    print("Usage ./gen.py <vertex number>")
num_vertices = int(sys.argv[1])
print(num_vertices)
for i in range(0, num_vertices):
    connect_range = 3
    j_start = max(0, i - connect_range)
    j_end = min(num_vertices, i + connect_range)
    for j in range(j_start, j_end):
        print(str(i) + " " + str(j) + " " + str(random.randrange(1,20)))


