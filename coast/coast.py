N, M = map(int, input().split(" "))
output = [[0 for _ in range(M + 2)] for _ in range(N + 2)]

for i in range(1, N + 1):
    line = list(map(int, input()))
    for j in range(1, M + 1):
        output[i][j] = line[j - 1]

def ones_in_neighbour(i, j) -> int:
    local_count = 0
    if j <= M:
        if output[i][j + 1] == 1:
            local_count+=1
    if j >= 1:
        if output[i][j - 1] == 1:
            local_count+=1
    if i <= N:
        if output[i + 1][j] == 1:
            local_count+=1
    if i >= 1:
        if output[i - 1][j] == 1:
            local_count+=1
    return local_count


visited = [[False for _ in range(M + 2)] for _ in range(N + 2)]

def dfs_iterative():
    count = 0
    stack = [(0, 0)]
    while stack:
        i, j = stack.pop()
        if i < 0 or i >= N + 2 or j < 0 or j >= M + 2:
            continue
        if visited[i][j]:
            continue
        visited[i][j] = True
        if output[i][j] == 0:
            stack.append((i - 1, j))
            stack.append((i + 1, j))
            stack.append((i, j - 1))
            stack.append((i, j + 1))

            count += ones_in_neighbour(i, j)
    return count

count  = dfs_iterative()
print(count)

