
// Binary Search Approach of Finding LIS by
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums) {

  // Binary search approach
  int n = nums.size();
  vector<int> ans;
  ans.push_back(nums[0]);

  for (int i = 1; i < n; i++) {
    if (nums[i] > ans.back()) {

      // If the current number is greater
      // than the last element of the answer
      // vector, it means we have found a
      // longer increasing subsequence.
      // Hence, we append the current number
      // to the answer vector.
      ans.push_back(nums[i]);
    } else {

      // If the current number is not
      // greater than the last element of
      // the answer vector, we perform
      // a binary search to find the smallest
      // element in the answer vector that
      // is greater than or equal to the
      // current number.

      // The lower_bound function returns
      // an iterator pointing to the first
      // element that is not less than
      // the current number.
      int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();

      // We update the element at the
      // found position with the current number.
      // By doing this, we are maintaining
      // a sorted order in the answer vector.
      ans[low] = nums[i];
    }
  }

  // The length of the answer vector
  // represents the length of the
  // longest increasing subsequence.
  return ans.size();
}

int lengthOfLNDS(vector<int> &nums) {
  // Binary search approach
  int n = nums.size();
  vector<int> ans;
  ans.push_back(nums[0]);

  for (int i = 1; i < n; i++) {
    if (nums[i] >= ans.back()) {

      // If the current number is greater or equal to
      // the last element of the answer
      // vector, it means we have found a
      // longer non-decreasing subsequence.
      // Hence, we append the current number
      // to the answer vector.
      ans.push_back(nums[i]);
    } else {

      // If the current number is not
      // greater than the last element of
      // the answer vector, we perform
      // a binary search to find the smallest
      // element in the answer vector that
      // is greater than.
      //
      // The upper_bound function returns
      // an iterator pointing to the first
      // element that is upper than
      // the current number.
      int low = upper_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();

      // We update the element at the
      // found position with the current number.
      // By doing this, we are maintaining
      // a sorted order in the answer vector.
      ans[low] = nums[i];
    }
  }

  // The length of the answer vector
  // represents the length of the
  // longest increasing subsequence.
  return ans.size();
}

// Driver program to test above function
int main() {
  vector<int> nums = {10, 22, 9, 33, 21, 21, 50, 41, 60};
  // Function call
  printf("Length of LNDS is %d\n", lengthOfLNDS(nums));
  printf("Length of LIS is %d\n", lengthOfLIS(nums));
  return 0;
}
