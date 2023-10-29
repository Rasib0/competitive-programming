#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  // Brute force solution, (my old code)
  void dfs(vector<int> &candidates, int target, int index, vector<int> &path,
           vector<vector<int>> &result) {
    if (target < 0) {
      return;
    }
    if (target == 0) {
      result.push_back(path);
      return;
    }
    for (int i = index; i < candidates.size(); i++) {
      path.push_back(candidates[i]);
      dfs(candidates, target - candidates[i], i, path, result);
      path.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> dummy;

    dfs(candidates, target, 0, dummy, result);

    return result;
  }
};
