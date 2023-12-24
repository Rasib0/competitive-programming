import sys
sys.setrecursionlimit(10**6)
lines = sys.stdin.read().splitlines()

# inputs
N = int(lines[0])

graph = {}
for i in range(N):
    line = lines[1 + i].strip()
    key, neighours = line.split(":")
    if neighours != "":
        graph[key] = neighours.strip().split(" ")


start = lines[N + 1]

# remove nodes without any dependencies


def invert_map(map):
    inverted_map = {}
    for key, neighbours in map.items():
        for neighbour in neighbours:
            if neighbour not in inverted_map:
                inverted_map[neighbour] = [key]
            else:
                inverted_map[neighbour].append(key)
    return inverted_map


inverted_graph = invert_map(graph)

# topological sort
def toposort(graph):
    output = []
    visited = set()

    def dfs(node):
        if node in visited:
            return
        for neighour in graph.get(node, []):
            dfs(neighour)

        visited.add(node)
        output.append(node)

    dfs(start)
    return output


for i in reversed(toposort(inverted_graph)):
    print(i)

# code works but only if you increase stack limit.
