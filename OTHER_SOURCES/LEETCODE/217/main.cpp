#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {}

bool lc217(vector<int> &nums) {

  unordered_set<int> nums_set;

  for (auto num : nums) {
    nums_set.insert(num);
  }

  return nums_set.size() < nums.size();
}

vector<int> twoSum(vector<int> nums, int target) {
  unordered_map<int, int> nums_map;
  vector<int> output;

  for (int i = 0; i < nums.size(); ++i) {
    // if num in nums_map
    if (nums_map.count(nums[i])) {
      return {i, nums_map[i]};
    } else {
      nums_map[nums[i]] = i;
    }
  }
  return output;
}

vector<vector<int>> threeSumBF(vector<int> nums, int target) {
  set<vector<int>> output;
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      for (int k = j + 1; k < nums.size(); ++k) {
        if (nums[i] + nums[j] + nums[k] == 0) {
          vector<int> temp = {nums[i], nums[j], nums[k]};
          sort(temp.begin(), temp.end());
          output.insert(temp);
        }
      }
    }
  }

  return vector<vector<int>>(output.begin(), output.end());
}
vector<vector<int>> threeSum(vector<int> nums, int target) {
  unordered_map<int, int> nums_map;
}
