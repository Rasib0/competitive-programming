import sys

outputs = []

k = 0
while True:
    line = sys.stdin.readline().strip()

    if line == ".":
        break

    count = 0
    length = len(line)

    for i in range(1, length + 1):
        if length % i != 0:
            continue

        if line[-i:] * int(length / i) == line:
            count = int(length / i)
            break

    print(count)
