from collections import defaultdict


def dfs(graph):
    stack = []  # swap to queue for bfs
    visited = set()
    stack.append((0, 0))

    # this dfs only adds neighbor of each element once
    # but you can have an element multiple times in the stack
    # because if A, B are in the stack and they both have a neighbor C, then C is added to the stack twice

    while stack:
        top = stack.pop()
        if top is visited:
            continue
        visited.add(top)
        for neighbor in graph[top]:
            if neighbor not in visited:
                stack.append(neighbor)


def dfs_recursive(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs_recursive(graph, neighbor, visited)


class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            # path compression
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        # union by rank
        px, py = self.find(x), self.find(y)
        if px == py:
            return False
        if self.rank[px] < self.rank[py]:
            self.parent[px] = py
        elif self.rank[px] > self.rank[py]:
            self.parent[py] = px
        else:
            self.parent[py] = px
            self.rank[px] += 1
        return True


# ---- TRIE -----
class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
        cur.endOfWord = True

    def search(self, word: str) -> bool:
        cur = self.root
        for c in word:
            if c not in cur.children:
                return False
            cur = cur.children[c]
        return cur.endOfWord

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for c in prefix:
            if c not in cur.children:
                return False
            cur = cur.children[c]
        return True


def count_scc_clean_code_dirty_implementation(graph):
    """
    Kosaraju's algorithm
    step 1: dfs on the graph, to mark visited nodes and add them to the stack
    step 2: transpose the graph
    step 3: dfs on the transposed graph for every unvisited node until the stack is empty
    step 4: count the number of times dfs is called
    """

    def dfs(node, graph, o_stack, o_visited):
        o_visited.add(node)
        for neighbor in graph[node]:
            if neighbor not in o_visited:
                dfs(neighbor, graph, o_stack, o_visited)
        o_stack.append(node)

    def transpose(graph):
        transposed = defaultdict(list)
        for node in graph:
            for neighbor in graph[node]:
                transposed[neighbor].append(node)
        return transposed

    if not graph:
        return 1

    stack = []
    visited = set()

    for vertex in list(graph):
        if vertex not in visited:
            dfs(vertex, graph, stack, visited)

    transpose_graph = transpose(graph)
    visited.clear()
    scc = 0

    while len(visited) < len(graph):  # or while stack (both works)
        node = stack.pop()
        if node not in visited:
            dfs(node, transpose_graph, [], visited)  # we don't need the stack here
            scc += 1
    return scc


def count_scc(graph):
    """
    Kosaraju's algorithm
    step 1: dfs on the graph, to mark visited nodes and add them to the stack
    step 2: transpose the graph
    step 3: dfs on the transposed graph for every unvisited node until the stack is empty
    step 4: count the number of times dfs is called
    """

    def dfs(node, graph, o_stack, o_visited):
        o_visited.add(node)
        for neighbor in graph[node]:
            if neighbor not in o_visited:
                dfs(neighbor, graph, o_stack, o_visited)
        o_stack.append(node)

    def dfs_scc(node, in_graph, o_visited):
        o_visited.add(node)
        for neighbor in in_graph[node]:
            if neighbor not in o_visited:
                dfs_scc(neighbor, in_graph, o_visited)

    def transpose(graph):
        transposed = defaultdict(list)
        for node in graph:
            for neighbor in graph[node]:
                transposed[neighbor].append(node)
        return transposed

    if not graph:
        return 1

    stack = []
    visited = set()

    for vertex in list(graph):
        if vertex not in visited:
            dfs(vertex, graph, stack, visited)

    transpose_graph = transpose(graph)
    visited.clear()
    scc = 0

    while len(visited) < len(graph):  # or while stack (both works)
        node = stack.pop()
        if node not in visited:
            # could just use dfs with [] stack
            dfs_scc(node, transpose_graph, visited)  # we don't need the stack here
            scc += 1
    return scc
