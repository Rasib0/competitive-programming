from collections import defaultdict
while True:
    n, m = [int(j) for j in input().split()] # number of intersections

    if n == 0 and m == 0:
        break

    graph = defaultdict(defaultdict)

    for i in range(m):
        x, y, f = [float(j) for j in input().split()] # corridor between x and y
        graph[x][y] = f

    import heapq

    def dijkstra(graph, start):
        distances = {node: float('infinity') for node in graph}
        distances[start] = 0
        pq = [(0, start)]
        while pq:
            current_distance, current_node = heapq.heappop(pq)
            if current_distance > distances[current_node]:
                continue
            for neighbor, weight in graph[current_node].items():
                distance = current_distance + weight
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(pq, (distance, neighbor))
        return distances

    distances = dijkstra(graph, 0)
