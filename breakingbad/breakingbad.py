from collections import defaultdict

n = int(input())
nodes = [input() for i in range(n)]

m = int(input())

graph = defaultdict(lambda: [])

for i in range(m):
    x, y = input().split()
    graph[x].append(y)
    graph[y].append(x)
    
#print(nodes)
#print(graph)

# our visited array is called colored
# it will store the color
# The three color value are -1, 0, 1
# -1 means unvisited, 0 and 1 refer to blue and red respectively
colored = {}
def bfs(start):
    from collections import deque
    q = deque()
    q.append(start)
    colored[start] = 0
    while q:
        top = q.popleft()
        for nei in graph[top]:
            # if a neighbor is already colored check if they match else return impossible
            if not nei in colored:
                q.append(nei)
                colored[nei] = 1 - colored[top]
            else:
                if colored[nei] == colored[top]:
                    print("impossible")
                    exit()    

for n in nodes:
    if n not in colored:
        bfs(n)
        
blue = []
red = []
for k, color in colored.items():
    if color == 0:
        blue.append(k)
    else:
        red.append(k)

print(*blue)
print(*red)
        