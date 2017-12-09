#!/usr/bin/env julia

INFINITY = 0x7f7f7f7f

function dijkstra(edges::Array{Int32,2}, nv::Int32, src::Int32, dest::Int32)
    visited = Array{Int32}(nv)
    dist = Array{Int32}(nv)
    for i = 1:nv
        dist[i] = edges[src,i]
        visited[i] = 0
    end
    min_index = -1
    visited[src] = 1
    for i = 1:nv
        min_value = INFINITY
        for j = 1:nv
            if visited[j] == 0 && dist[j] < min_value
                min_value = dist[j]
                min_index = j
            end
        end
        visited[min_index] = 1
        for k = 1:nv
            if (visited[k] == 0 && dist[k] > (dist[min_index] + edges[min_index, k]))
                dist[k] = dist[min_index] + edges[min_index, k]
            end
        end
    end
    return dist[dest]
end


f = open("edges.txt")
x = readline(f)
n = parse(Int32, x)
lines = readlines(f)

edges = Matrix{Int32}(n, n)
for i = 1:n
    for j = 1:n
        edges[i,j] = INFINITY
    end
end

for l in lines
    tokens = split(l)
    i = parse(Int32, tokens[1]) + 1
    j = parse(Int32, tokens[2]) + 1
    dist = parse(Int32, tokens[3])
    edges[i,j] = dist
end

tic()
for i = 1:10
    dijkstra(edges, n, convert(Int32, 1), n)
end
print("julia running time: ")
toc()


