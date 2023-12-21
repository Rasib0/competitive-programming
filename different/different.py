import sys

lines = sys.stdin.read().splitlines()

for li in lines:
    a, b = map(int, li.split())
    print(abs(a - b))
