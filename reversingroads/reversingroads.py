import sys
lines = sys.stdin.read().splitlines()
# print(lines)

graph = {}
i = 0
while i < len(lines):
    m, n = map(int, lines[i].split())
    i += 1
    for j in range(n):
        fro, to = map(int, lines[i+j].split())
        graph[fro] = to
    i += n   

# print(graph)
# graph is correct; now only need to find the strongly connected components
    

def kosaraju():
    pass