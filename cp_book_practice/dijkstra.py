class Solution:
    def shortestPath(self, n: int, edges: list[list[int]], src: int) -> dict[int, int]:
        adj = [[] for _ in range(n)]

        for s, d, w in edges:
            adj[s].append((d, w))

        minheap = [(0, src)]  # (weight, node)
        import heapq

        # argument: greedily the weight added will be the shortest path to that node
        answer = {}
        while minheap:
            w1, n1 = heapq.heappop(minheap)
            if n1 in answer:  # greedy so once we find the shortest path, we can stop
                continue
            answer[n1] = w1
            for n2, w2 in adj[n1]:  # wtf
                if n2 not in answer:
                    heapq.heappush(minheap, (w1 + w2, n2))

        for i in range(n):
            if i not in answer:
                answer[i] = -1

        return answer


n = 3
edges = [[0, 1, 3], [1, 2, 1], [2, 0, 4]]
src = 0

print(Solution().shortestPath(n, edges, src))
