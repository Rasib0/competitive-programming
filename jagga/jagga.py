from sys import stdin
def jagga_tax_no_numpy(N, M, roads):
    graph = [[float('inf')] * N for _ in range(N)]  # Initialize the graph with infinite distances

    # Construct the graph based on the road connections
    for u, v in roads:
        graph[u-1][v-1] = 1  # As the graph is 0-indexed in our representation
        graph[v-1][u-1] = 1

    for k in range(N):
        for i in range(N):
            for j in range(N):
                if graph[i][k] + graph[k][j] < graph[i][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]

    # Initialize JRP counts for each crossing
    JRP = [0] * N

    # Count the number of shortest paths passing through each crossing
    for i in range(N):
        for j in range(N):
            if i != j:
                for k in range(N):
                    if i != k and j != k and graph[i][j] == graph[i][k] + graph[k][j]:
                        JRP[k] += 1

    top_crossings = sorted(range(1, N + 1), key=lambda x: JRP[x-1], reverse=True)[:5]
    return top_crossings

# Example test case
# N = 6
# M = 6
roads = [[1, 2], [1, 3], [2, 4], [3, 4], [4, 5], [4, 6]]

inputs = stdin.read().splitlines()
ln = 0

t = int(inputs[ln])
ln += 1
N,M = map(int, inputs[ln].split())
ln += 1

for _ in range(M):
	roads.append(list(map(int, inputs[ln].split())))
	ln += 1

output = jagga_tax_no_numpy(N, M, roads)
print("\n".join(map(str, output)))
