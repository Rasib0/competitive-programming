from sys import stdin
import math

inputs = stdin.read().splitlines()
ln = 0


while True:
    nums = list(map(int, inputs[ln].split()))
    ln += 1
    n = nums[0]

    if n == 0:
        break

    res, outInd = 0, 0
    dp = [0 for _ in range(n)]
    prev = [-1 for _ in range(n)]

    for i in range(n):
        maxInc = 0
        currPrev = -1
        for j in range(i):
            if nums[j+1] < nums[i+1]:
                if dp[j] > maxInc or (dp[j] == maxInc and nums[j+1] < nums[currPrev+1]):
                    maxInc = dp[j]
                    currPrev = j

        dp[i] = maxInc + 1
        prev[i] = currPrev

        if dp[i] > res or (dp[i] == res and nums[i+1] < nums[outInd+1]):
            res = dp[i]
            outInd = i

    i = outInd
    res_seq = ""

    while i != -1:
        if res_seq == "":
            res_seq = str(nums[i+1]) + res_seq
        else:
            res_seq = str(nums[i+1]) + " " + res_seq
        i = prev[i]

    res_seq = str(res) + " " + res_seq
    print(res_seq)
