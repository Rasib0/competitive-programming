from collections import defaultdict
import sys

lines = sys.stdin.read().splitlines()
# print(lines)


def make_graph_from_edges(edge_list):
    graph = defaultdict(list)
    for edge in edge_list:
        graph[edge[0]] += [edge[1]]
    return graph
# returns true if the graph is strongly connected
def kosaraju(graph):

    if len(graph) == 0:
        return True

    # step 1: dfs on the graph
    # step 2: transpose the graph
    # step 3: dfs on the transposed graph
    # step 4: if all nodes are visited, return true
    # step 5: else, return false
    stack = []
    visited = set()

    # to find an ordering of the graph nodes and store them in the stack variable
    def dfs(node):
        visited.add(node)
        for child in graph[node]:
            if child not in visited:
                dfs(child)
        stack.append(node)

    # to transpose the graph
    def graph_transpose(graph):
        rev_graph = defaultdict(list)
        for node in graph:
            for child in graph[node]:
                rev_graph[node].append(child)
        return rev_graph
    
    def rev_dfs(node):
        visited.add(node)
        for child in rev_graph[node]:
            if child not in visited:
                rev_dfs(child)

    dfs(list(graph.keys())[0])
    rev_graph = graph_transpose(graph)
    visited.clear()

    node = stack.pop()
    if node not in visited:
        rev_dfs(node)
    if len(visited) == len(graph):
        return True
    else:
        return False

i = 0 # used to iterate through the lines
case = 1 # used to print the case number
while i < len(lines):
    graph = defaultdict(list)
    edge_list = []

    m, n = map(int, lines[i].split())
    i += 1

    for j in range(n):
        fro, to = map(int, lines[i+j].split())
        graph[fro] += [to]
        edge_list.append((fro, to))
    i += n
    
    if kosaraju(graph):
        print(f"Case {case}: valid")
    else:
        for j in range(len(edge_list)):
            edge_list_copy = edge_list.copy()
            edge_list_copy[j] = (edge_list[j][1], edge_list[j][0])
            copy_graph = make_graph_from_edges(edge_list_copy)

    
            if kosaraju(copy_graph):
                print(f"Case {case}: {edge_list[j][0]} {edge_list[j][1]}")
                break
        else:
            print(f"Case {case}: invalid")
      
    case += 1



# Output:
# Proposal is valid or not
# IF it is not valid, but by reversing the directing of one node, it will be valid
# print the two location of the node to be reversed