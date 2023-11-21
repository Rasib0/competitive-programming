from math import log10


def p(d):
    return log10(1 + (1 / d))


t = int(input())

for _ in range(t):
    occ = list(map(int, input().split()))
    total = 0
    for i in occ:
        total += i
    sum = 0
    for i in range(9):
        sum += abs(p(i + 1) - (occ[i] / total))
    print(sum * 100)
