# TODO
class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        ans = []
        n = len(candidates)
        def dfs(cur, cur_sum, idx):                       # try out each possible cases
            if cur_sum > target:
                return                   # this is the case, cur_sum will never equal to target
            if cur_sum == target: 
                ans.append(cur)
                return # if equal, add to `ans`
            for i in range(idx, n):
                dfs(cur + [candidates[i]], cur_sum + candidates[i], i) # DFS
        dfs([], 0, 0)
        return ans        

    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        idx_d = {val: idx for idx, val in enumerate(candidates)} # create {num:idx}
        dp = [[] for _ in range(target+1)]
        for i in range(1, target+1):                         # from 1 to target, O(M)
            for j in range(i):                               # O(M): for all previous calculated numbers
                for comb in dp[j]:                           # O(M) worst: check each of their combinations
                    start_idx = idx_d[comb[-1]]              # use start_idx to avoid repeats
                    for val in candidates[start_idx:]:       # O(N): try all candidates
                        if val + j == i:
                            dp[i].append(comb + [val]) 
            for candidate in candidates:                     # O(N): directly from candidates not from previous result 
                if candidate == i:
                    dp[i].append([candidate])
        return dp[-1]            


    def combinationSum3(self, candidates: list[int], target: int) -> list[list[int]]:
        dp = [[] for _ in range(target+1)]
        for c in candidates:                                  # O(N): for each candidate
            for i in range(c, target+1):                      # O(M): for each possible value <= target
                if i == c:
                    dp[i].append([c])
                for comb in dp[i-c]:
                    dp[i].append(comb + [c]) # O(M) worst: for each combination
        return dp[-1]


print(Solution().combinationSum([2,3,6,7], 12))
print(Solution().combinationSum2([2,3,6,7], 12))
print(Solution().combinationSum3([2,3,6,7], 12))
