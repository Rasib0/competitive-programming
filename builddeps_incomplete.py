import sys
lines = sys.stdin.read().splitlines()

# inputs
N = int(lines[0])

graph = {}
for i in range(N):
    line = lines[1 + i].strip()
    key, neighours = line.split(":")
    if neighours != '':
        graph[key] = neighours.strip().split(" ")


start = lines[N + 1]

# remove nodes without any dependencies

def invert_map(map):
    inverted_map = {}
    for key, neighbours in map.items():
        if key not in inverted_map:
            inverted_map[key] = []
        for neighbour in neighbours:
            if neighbour not in inverted_map:
                inverted_map[neighbour] = [key]
            else:
                inverted_map[neighbour].append(key)
    return inverted_map

inverted_graph = invert_map(graph)

def dfs():
    stack = []
    stack.append(start)
    visited = dict()
    out = [start]

    while stack:
        key = stack.pop()
        neighours = inverted_graph[key]

        visited[key] = True
        for i in neighours:
                if i in visited:
                    continue
                out.append(i)
                stack.append(i)
                visited[i] = True

    for i in out:
        print(i)


def dfs2():
    out = []
    visited = {}

    def dfs_util(key):
        if key in visited:
            return
        neighours = inverted_graph[key]
        for i in neighours:
            dfs_util(i)

        visited[key] = True
        out.append(key)

    dfs_util(start)

    for i in reversed(out):
        print(i)

dfs()
