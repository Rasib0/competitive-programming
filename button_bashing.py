import sys
import math
from collections import deque

lines = sys.stdin.read().splitlines()
test = int(lines[0])

for i in range(1, test * 2, 2):
    n, t = list(map(int, lines[i].split(" ")))
    lis = list(map(int, lines[i+1].split(" ")))

    dist = [math.inf for _ in range(3601)]
    dist[0] = 0
    q = deque()
    q.append(0)

    while q:
        u = q.popleft()

        for v in lis:
            time = u + v
            if time < 0:
                time = 0
            if time > 3600:
                time = 3600
            if dist[time] == math.inf:
                q.append(time)
                dist[time] = dist[u] + 1



    for k in range(t, 3601):
        if dist[k] != math.inf:
            print(dist[k], k - t)
            break




    # minimize the number of required button presses
    # 0 second <-> 1 hours
    # If a button press results in < 0, cooking time is 0
        # if > 1 hours microwave = 1 hours
    # Initial 0 second
    # given button find least amount of button to let microwave run for a cetain amount of time
    # if not possible, smallest achievable cooking time above the target (upperbound)

