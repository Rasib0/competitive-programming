#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {

  map<int, int> count;
  vector<vector<int>> thing(nums.size(), vector<int>{});

  for (auto &num : nums) {
    count[num]++;
  }

  for (auto &[k, e] : count) {
    thing[e].push_back(k);
  }

  vector<int> answer;

  for (int i = thing.size() - 1; i >= 0; i--) {
    for (auto &x : thing[i]) {
      answer.push_back(x);
    }

    if (answer.size() >= k) {
      return answer;
    }
  }

  return answer;
}

int main() {
  vector<int> nums{1, 1, 1, 2, 2, 3};
  int k = 2;

  vector<int> answer = topKFrequent(nums, k);

  for (auto &x : answer) {
    cout << x << " ";
  }

  cout << endl;
  return 0;
}
