#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    // find the pivot; the index before the longest suffix increasing sequence
    int pivot = -1;

    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] < nums[i + 1]) {
        pivot = i;
      }
    }

    // if pivot is -1 => it is in reverse order
    // else => it is in normal order
    if (pivot < 0) {
      reverse(nums.begin(), nums.end());
    } else {

      // smallest number greater than pivot
      int l = pivot;

      for (int i = pivot + 1; i < nums.size(); i++) {
        if (nums[pivot] < nums[i]) {
          l = i;
        }
      }

      iter_swap(nums.begin() + pivot, nums.begin() + l);
      reverse(nums.begin() + pivot + 1, nums.end());
    }
  }
};
