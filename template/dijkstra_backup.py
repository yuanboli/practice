#!/usr/bin/env python3
import time

INFINITY = 0x7f7f7f7f
edges = {}

def key(i, j):
    return str(i) + ", " + str(j)

def dijkstra(nv, src, dest):
    '''dijkstra'''
    dist = {}
    visited = {}
    for i in range(nv):
        dist[i] = edges[key(src, i)]
        visited[i] = 0

    visited[src] = 1
    for i in range(1, nv):
        min_value = INFINITY
        for j in range(nv):
            if(visited[j] == 0 and (dist[j] < min_value)):
                min_value = dist[j]
                min_index = j

        visited[min_index] = 1
        for k in range(nv):
            if(visited[k] == 0 and dist[k] > (dist[min_index] + edges[key(min_index, k)])):
                dist[k] = dist[min_index] + edges[key(min_index, k)]

    return dist[dest]

with open('edges.txt', 'r') as f:
    first_line = f.readline()
    n = int(first_line.split()[0])
    for i in range(n):
        for j in range(n):
            edges[key(i, j)] = INFINITY
    for line in f:
        tokens = line.split()
        i = int(tokens[0])
        j = int(tokens[1])
        dist = int(tokens[2])
        edges[key(i, j)] = dist

start = time.time()
for i in range(10):
    dijkstra(n, 0, n-1)
print("python running time: " + str(time.time() - start))

