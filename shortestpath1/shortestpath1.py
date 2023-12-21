from collections import defaultdict
import heapq

while True:
    n, m, q, s = map(int, input().split())
    # n is the number of nodes
    # m is the number of edges
    # q is queries
    # s starting node
    if n == 0:
        break

    g = defaultdict(list)
    for i in range(m):
        u, v, w = map(int, input().split())
        g[u].append((w, v))

    # dijstra's algorithm
    st = [(0, s)]

    queries = [int(input()) for _ in range(q)]

    visited = {}

    while st:
        wt, top = heapq.heappop(st)
        if top in visited:
            continue

        visited[top] = wt

        if all(qry in visited for qry in queries):
            break

        for nwt, nxt in g[top]:
            heapq.heappush(st, (nwt + wt, nxt))

    # for qry in queries:
    #     if qry in visited:
    #         print(visited[qry])
    #     else:
    #         print("Impossible")

    # printing like a maniac for fun
    print("\n".join(str(visited.get(qry, "Impossible")) for qry in queries))
