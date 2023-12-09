from collections import defaultdict
import sys

lines = sys.stdin.read().splitlines()
# print(lines)


def make_graph_from_edges(edge_list):
    graph = defaultdict(list)
    for edge in edge_list:
        graph[edge[0]] += [edge[1]]
    return graph


def kosaraju(graph):
    # step 1: dfs on the graph, to mark visited nodes and add them to the stack
    # step 2: transpose the graph
    # step 3: dfs on the transposed graph
    # step 4: count the number of times dfs is called
    if len(graph) == 0:
        return True
    stack = []
    visited = set()

    def mark_reachable_dfs(node, input_graph, output_stack, output_visited):
        output_visited.add(node)
        for child in input_graph[node]:
            if child not in visited:
                mark_reachable_dfs(child, input_graph, output_stack, output_visited)
        output_stack.append(node)

    def transpose(graph):
        rev_graph = defaultdict(list)
        for node in graph:
            for child in graph[node]:
                rev_graph[child].append(node)
        return rev_graph

    first_node = list(graph.keys())[0]

    mark_reachable_dfs(first_node, graph, stack, visited)
    rev_graph = transpose(graph)

    scc = 0
    visited.clear()
    while len(visited) < len(graph):
        node = stack.pop()
        mark_reachable_dfs(node, rev_graph, [], visited)  # we don't need the stack here
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

    if kosaraju(graph) == 1:
        print(f"Case {case}: valid")
    else:
        for j in range(len(edge_list)):
            edge_list_copy = edge_list.copy()
            edge_list_copy[j] = (edge_list[j][1], edge_list[j][0])
            new_graph = make_graph_from_edges(edge_list_copy)

            if kosaraju(new_graph) == 1:
                print(f"Case {case}: {edge_list[j][0]} {edge_list[j][1]}")
                break
        else:
            print(f"Case {case}: invalid")

    case += 1


# Output:
# Proposal is valid or not
# IF it is not valid, but by reversing the directing of one node, it will be valid
# print the two location of the node to be reversed
