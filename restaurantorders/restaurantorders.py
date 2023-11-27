N = int(input())
prices = list(map(int, input().split()))

M = int(input())
t = list(map(int, input().split()))

max_target = max(t)

count = [0] * (max_target + 1)
dp = [[] for _ in range(max_target + 1)]

# dp[i] contains pairs (l, m) where l is the previous value (l <= T) and m is the index of the coin such that l + v[m] = j
# combination sum but only stores one path (using prev pointers)
# count tells you if there are multiple paths ( > 1)
def combination_sum(T, v):
    global dp, count

    dp = [[] for _ in range(T + 1)]
    count = [0 for _ in range(T + 1)]

    for i in range(len(v)):
        c = v[i]
        for j in range(c, T + 1):

            if j == c:
                dp[j].append((-1, i))
                count[j] += 1

            if count[j - c] > 1:
                count[j] = 2
            else:
                for _ in dp[j - c]:
                    dp[j].append((j - c, i))
                    count[j] += 1

combination_sum(max_target, prices)

for target in t:
    if count[target] == 0:
        print("Impossible")
    elif count[target] > 1:
        print("Ambiguous")
    else:
        output = []
        pair = dp[target][0]
        output.append(pair[1])

        while pair[0] != -1 and pair[0] != 0:
            pair = dp[pair[0]][0]
            output.append(pair[1])

        print(*map( lambda x: x + 1, reversed(output)))
