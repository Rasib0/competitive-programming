def rd(x):
    return (x + 5) // 10 * 10

def rsq(left, r):
    return arr[r] if left == 0 else arr[r] - arr[left - 1]

def dp(idx: int, divs: int):
    if memo[idx][divs]  != -1:
        return memo[idx][divs]
    if idx == n:
        return 0
    if divs == 0:
        return rd(rsq(idx, n - 1))

    memo[idx][divs] = min(
        rd(rsq(idx, div_pos - 1)) + dp(div_pos, divs - 1) 
        for div_pos in range(idx + 1, n + 1)
    )

    return memo[idx][divs]

n, d = map(int, input().split())
INF = 10**9
arr = list(map(int, input().split()))
ori = arr.copy()

memo = [[-1 for _ in range(d + 1)] for _ in range(n + 1)]
arr = [sum(ori[:i+1]) for i in range(n)]

print(dp(0, d))
