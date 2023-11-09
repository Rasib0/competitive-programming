import sys

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
        if key not in inverted_map:
            inverted_map[key] = []
        for neighbour in neighbours:
            if neighbour not in inverted_map:
                inverted_map[neighbour] = [key]
            else:
                inverted_map[neighbour].append(key)
    return inverted_map


inverted_graph = invert_map(graph)

print(inverted_graph)
