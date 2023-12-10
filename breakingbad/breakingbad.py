from collections import defaultdict, deque

n = int(input())
nodes = [input() for _ in range(n)]
m = int(input())
edges = [input().split() for _ in range(m)]


adj_list = defaultdict(list)

for i in edges:
    adj_list[i[0]].append(i[1])
    adj_list[i[1]].append(i[0])


stack = deque()
visited = {n: False for n in nodes}
colored_blue = {n: True for n in nodes}
stack.extend(nodes)

while stack:
    node = stack.pop()
    visited[node] = True
    for neighbor in adj_list[node]:
        if visited[neighbor] and colored_blue[neighbor] == colored_blue[node]:
            print("impossible")
            exit()
        if visited[neighbor]:
            continue
        stack.append(neighbor)
        colored_blue[neighbor] = not colored_blue[node]

blue = filter(lambda n: colored_blue[n], nodes)
red = filter(lambda n: not colored_blue[n], nodes)

print(*list(blue))
print(*list(red))
