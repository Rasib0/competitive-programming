from collections import defaultdict
n, m, f, s, t = map(int, input().split())

# n is nodes
# m is edges
# f is flights
# s is start 
# t is destination
INF = 10**9

graph = defaultdict(list)
for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((w, v))
    graph[v].append((w, u))

flights = defaultdict(list)
for _ in range(f):
    u, v = map(int, input().split())
    flights[u].append((0, v))


def dijkstra():
    import heapq
    from typing import List, Tuple

    pq: List[Tuple[int, int, bool]] = [(0, s, True)]

    dist_hasF = { i : INF for i in range(n) }
    dist_noF = { i : INF for i in range(n) }
    dist_hasF[s] = 0
    dist_noF[s] = 0

    while pq:
        dist, curr, hasF = heapq.heappop(pq)
        dist_hasF[curr] = dist

        for ndist, nei in graph[curr]:
            old_dis =  dist_hasF[nei]
            new_dis = dist + ndist

            if new_dis < old_dis:
                dist_hasF[nei] = new_dis
                heapq.heappush(pq, (new_dis, nei, hasF))

        if hasF:
            for ndist, nei in flights[curr]:
                old_dis =  dist_hasF[nei]
                new_dis = dist 

                if new_dis < old_dis:
                    dist_hasF[nei] = new_dis
                    heapq.heappush(pq, (new_dis, nei, False))

    return dist_hasF

print(dijkstra()[t])
