from collections import defaultdict
import sys

lines = sys.stdin.read().splitlines()


def make_graph_from_edges(edge_list):
    graph = defaultdict(list)
    for edge in edge_list:
        graph[edge[0]] += [edge[1]]
    return graph


def count_scc_clean_code_drity_implementation(graph):
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


i = 0  # used to iterate through the lines
case = 1  # used to print the case number
while i < len(lines):
    graph = defaultdict(list)
    edge_list = []

    m, n = map(int, lines[i].split())
    i += 1

    for j in range(n):
        fro, to = map(int, lines[i + j].split())
        graph[fro] += [to]
        edge_list.append((fro, to))
    i += n

    if count_scc(graph) == 1:
        print(f"Case {case}: valid")
    else:
        for j in range(len(edge_list)):
            edge_list_copy = edge_list.copy()
            edge_list_copy[j] = (edge_list[j][1], edge_list[j][0])
            new_graph = make_graph_from_edges(edge_list_copy)

            if count_scc(new_graph) == 1:
                print(f"Case {case}: {edge_list[j][0]} {edge_list[j][1]}")
                break
        else:
            print(f"Case {case}: invalid")

    case += 1


# Output:
# Proposal is valid or not
# IF it is not valid, but by reversing the directing of one node, it will be valid
# print the two location of the node to be reversed
