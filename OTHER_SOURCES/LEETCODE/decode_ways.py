def decode_ways(start, s: str, memo) -> int:
    n = len(s)

    if start == n:
        return 1

    if s[start] == '0':
        return 0

    if start in memo:
        return memo[start]

    ways = decode_ways(start + 1, s, memo)

    if start + 2 <= n:
        slice = s[start:start+2]
        if int(slice) <= 26:
            ways += decode_ways(start + 2, s, memo)

    memo[start] = ways
    return ways

inputs = ["12", "06", "226"]


for i in inputs:
    print(decode_ways(0, i, {}))
