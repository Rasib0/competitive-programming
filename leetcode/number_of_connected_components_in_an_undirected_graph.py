class Solution:
    def countComponents(self, n: int, edges: list[list[int]]) -> int:
        par = [i for i in range(n)]
        sz = [1] * n

        # find the root (of not tree)
        def find(n1):
            res = n1
            while res != par[res]:
                par[res] = par[par[res]]
                res = par[res]

            # add path compression here to make the tree flat TODO
            return res

        # union two nodes
        def union(n1, n2):
            p1, p2 = find(n1), find(n2)

            if p1 == p2:
             return 0

            # make the smaller p the parent
            if sz[p1] < sz[p2]:
                par[p1] = p2
                sz[p2] += sz[p1]
            else:
                par[p2] = p1
                sz[p1] += sz[p2]
            return 1

        res = n
        for n1, n2 in edges:
            res -= union(n1, n2)
        return res
