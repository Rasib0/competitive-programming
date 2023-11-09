import sys

lines = sys.stdin.read().splitlines()

# inputs
N = int(lines[0])

graph = {}
for i in range(N):
    line = lines[1 + i]
    key, neighours = line.split(":")
    if neighours != "":
        graph[key] = neighours.strip().split(" ")


start = lines[N + 1]

# solution


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

visited = {}


def bfs():
    from collections import deque

    queue = deque()
    queue.append(start)
    visited[start] = True

    while queue:
        key = queue.popleft()
        print(key)
        neighours = inverted_graph[key]

        filter_neighours = []

        for i in neighours:
            if i not in visited:
                filter_neighours += [i]
                visited[i] = True

        queue += filter_neighours


bfs()
