
from typing import List

# UnionFind
#
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        par = [i for i in range(n)]
        rank = [1 for i in range(n)]
            
        def find(u):
            if par[u] != u:
                par[u] = find(par[u])  # Path compression
            return par[u]

        def union(u, v):
            p1, p2 = find(u), find(v)

            if p1 == p2:
                return False  # No union performed
            
            if rank[p1] > rank[p2]:
                par[p2] = p1
            elif rank[p1] < rank[p2]:
                par[p1] = p2
            else:
                par[p2] = p1
                rank[p1] += 1  # Update rank of the parent

            return True  # Union performed

        res = n
        for i in range(len(isConnected)):
            for j in range(len(isConnected[0])):
                if isConnected[i][j] == 1:
                    if union(i, j):
                        res -= 1  # Decrease the count only when a union is performed

        return res
