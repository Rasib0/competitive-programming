def not_so_dijkstra_for_factors(adj_list, n):
    # returns least factor path to all nodes from 0
    # uses a  max priority queue (max heap)
    # similar to dijkstra but instead of adding distances, we multiply them
    import heapq

    visited = [False] * n
    pq = [(-1, 0)]
    ans = [0] * n

    while pq:
        prev_f, n1 = heapq.heappop(pq)

        if visited[n1]:
            continue

        ans[n1] = -prev_f
        visited[n1] = True

        for n2, f in adj_list[n1]:
            if not visited[n2]:
                heapq.heappush(pq, (prev_f * f, n2))
    return ans


while True:
    n, m = [int(j) for j in input().split()]  # number of intersections

    if n == 0 and m == 0:
        break

    adj = [[] for _ in range(n)]

    for i in range(m):
        x, y, f = input().split()  # corridor between x and y
        adj[int(x)] += [(int(y), float(f))]
        adj[int(y)] += [(int(x), float(f))]

    distances = not_so_dijkstra_for_factors(adj, n)

    print(f"{distances[n - 1]:.4f}")
