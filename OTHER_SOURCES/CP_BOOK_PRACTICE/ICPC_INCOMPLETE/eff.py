from collections import defaultdict
from itertools import combinations
from itertools import product

t = int(input())
k = int(input())

m = defaultdict(list)

c = 0
for i in range(k):
    _  = int(input())
    line = list(map(int, input().split()))
    for dep in line:
        m[dep].append(c)
    c += 1

deps = m.keys()

final = 0
for vector in combinations(deps, k):
    arr = []
    for key in vector:
        arr.append(m[key])

    combinations = product(*arr)
    unique_sets_count = len({tuple(sorted(combination)) for combination in combinations})
    if unique_sets_count > 0:
        final += 1

print(final)
