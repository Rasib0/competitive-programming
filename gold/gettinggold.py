import sys

sys.setrecursionlimit(10**6)

lines = sys.stdin.read().splitlines()
graph = list(map(list, lines))
graph = graph[1:]

h = len(graph)
w = len(graph[0])

visited = set()


def dfs(x, y):
    gold = 0
    if not (0 <= x < h and 0 <= y < w) or (x, y) in visited or graph[x][y] == "#":
        return 0

    if graph[x][y] == "G":
        gold += 1

    visited.add((x, y))
    n_indices = [(x + n[0], y + n[1]) for n in [(1, 0), (0, 1), (0, -1), (-1, 0)]]

    for a, b in n_indices:
        if graph[a][b] == "T":
            return gold

    for a, b in n_indices:
        gold += dfs(a, b)

    return gold


for i in range(h):
    for j in range(w):
        if graph[i][j] == "P":
            print(dfs(i, j))
