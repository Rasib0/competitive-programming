from collections import defaultdict

n = int(input())
graph = defaultdict(set)

for i in range(n):
    line = list(input().split())
    to = line[1:]

    for j in to:
        graph[line[0]].add(j)
        graph[j].add(line[0])

fro, to = input().split()

def bfs(graph, start, end):
    from collections import deque
    visited = set()
    q = deque()
    q.append((start, [start]))

    while q:
        node, path = q.popleft()
        if node in visited:
            continue
        visited.add(node)

        if node == end:
            return True, path
        for i in graph[node]:
            q.append((i, path + [i]))

    return False, []

pathExists, path = bfs(graph, fro, to)

if pathExists:
    for i in path:
        print(i, end=' ')
    print()
else:
    print("no route found")
    
