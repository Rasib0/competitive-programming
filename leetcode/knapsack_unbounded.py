# Bounded Knapsack Tabulation:
# we look at the previous row (up and up-left)
# because we can only use each item once
#  you need minimum 2 rows because we are storing:
#  - the calculated curr row (for next iteration)
#  - and prev row for  calculating curr row

# In Unbounded Knapsack:
# we can use each item as many times as we want so we look at the same row (up and left - of same row)
# we can store this in one row as we are using the previous calculated values of the current row + the entry of prev row right above
# So it nicely fits in 1D array

def unboundedKnapsack(w:list, v:list, target:int):
    n = len(w)
    dp = [0] * (target+1)
    for i in range(1, target+1):
        for j in range(n):
            if w[j] <= i:
                dp[i] = max(dp[i], dp[i-w[j]] + v[j])
    return dp[target]






def coinChange1D(amount, coins):
    dp = [0] * (amount+1)
    dp[0] = 1
    for coin in coins:
        for i in range(1, amount+1):
            if i >= coin:
                dp[i] += dp[i-coin]
    return dp[amount]



def coinChangeTopDown(amount, coins):
     cache = {}
     def dfs(i, amount):
        if amount == 0:
            return 1
        if amount < 0:
            return 0
        if i == len(coins):
            return 0
        if (i, amount) in cache:
            return cache[(i,amount)]
        
        cache[(i,amount)] = dfs(i, amount - coins[i]) + dfs(i + 1, amount)
        return cache[(i,amount)]

     return dfs(0, amount)

print(unboundedKnapsack([1, 2, 3], [15, 20, 50], 5)) # 80
print(coinChange1D(7, [1, 3, 5])) # 4
print(coinChangeTopDown(7, [1, 3, 5])) # 4
