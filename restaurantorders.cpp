#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

#define int long long int
#define endl "\n"
#define vec vector
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0);

using namespace std;

struct PairHash {
  template <typename T1, typename T2>
  auto operator()(const pair<T1, T2> &p) const -> size_t {
    return (hash<T1>{}(p.first) << 32) | hash<T2>{}(p.second);
  }
};
// Coin Change 2 - LeetCode

void combination_sum(int T, int index, vector<int> &v, int &count,
                     vector<int> &path, vec<int> &ans,
                     unordered_map<pair<int, int>, int, PairHash> &dp) {
  if (T < 0) {
    return;
  }

  if (dp.find({T, index}) != dp.end()) {
    count += dp[{T, index}];
    return;
  }

  if (count > 1) {
    return;
  }

  if (T == 0) {
    count++;
    ans = path;
    return;
  }

  for (int i = index; i < v.size(); i++) {
    path.push_back(i + 1);
    combination_sum(T - v[i], i, v, count, path, ans, dp);
    dp[{T, i}] = count;
    path.pop_back();
  }
}

int32_t main() {
  IOS;

  // input
  int N;
  cin >> N;
  vec<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  int M;
  cin >> M;
  vec<int> t(M);
  for (int i = 0; i < M; i++) {
    cin >> t[i];
  }

  // solve for each testcases
  for (int i = 0; i < M; i++) {
    vec<int> path_dummy;
    vec<int> ans;

    unordered_map<pair<int, int>, int, PairHash> dp;
    int count = 0;
    combination_sum(t[i], 0, v, count, path_dummy, ans, dp);

    if (count == 0)
      cout << "Impossible" << endl;
    else if (count > 1)
      cout << "Ambiguous" << endl;
    else {
      for (auto x : ans) {
        cout << x << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
