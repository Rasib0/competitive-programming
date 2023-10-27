// marked
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int knapsack_unbounded(vector<int> &w, vector<int> &p,
                       unordered_map<int, int> &memo,
                       unordered_map<int, int> &prev, int size) {
  if (size < 0)
    return numeric_limits<int>::min();
  if (size == 0)
    return 0;

  if (memo.find(size) != memo.end()) {
    return memo[size];
  }

  int maximum = 0;
  int selected_item = -1;

  for (int i = 0; i < w.size(); i++) {
    int temp = knapsack_unbounded(w, p, memo, prev, size - w[i]) + p[i];

    if (temp > maximum) {
      maximum = temp;
      selected_item = i;
    }
  }

  memo[size] = maximum;
  prev[size] = selected_item;

  return maximum;
}

// hashing function
struct PairHash {
  template <typename T1, typename T2>
  auto operator()(const pair<T1, T2> &p) const -> size_t {
    return (hash<T1>{}(p.first) << 32) | hash<T2>{}(p.second);
  }
};

int knapsack_topdown(vector<int> &w, vector<int> &p,
                     unordered_map<pair<int, int>, int, PairHash> &memo,
                     int size, int i) {
  if (size == 0 or i == 0)
    return 0;

  int inc_sum = 0;
  pair<int, int> key = {size, i};

  if (memo.find(key) != memo.end())
    return memo[key];

  if (size >= w[i - 1])
    inc_sum = p[i - 1] + knapsack_topdown(w, p, memo, size - w[i - 1], i - 1);

  int exc_sum = knapsack_topdown(w, p, memo, size, i - 1);

  memo[key] = max(inc_sum, exc_sum);

  return memo[key];
}

int knapsack_bottomup(vector<int> &w, vector<int> &p, vector<vector<int>> &memo,
                      int size, int n) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= size; j++) {
      if (i == 0 or j == 0)
        memo[i][j] = 0;
      else if (w[i - 1] <= j)
        memo[i][j] = max(memo[i - 1][j], p[i - 1] + memo[i - 1][j - w[i - 1]]);
      else {
        memo[i][j] = memo[i - 1][j];
      }
    }
  }
  return memo[n][size];
}

// subset target sum  + knapsack
int main() {
  vector<int> w = {1, 4, 2};
  vector<int> p = {2, 8, 4};
  int size = 5;

  unordered_map<int, int> prev_unbound;
  unordered_map<int, int> memo_unbound;

  int profit_unbounded =
      knapsack_unbounded(w, p, memo_unbound, prev_unbound, size);
  cout << "Profit: " << profit_unbounded << endl;

  // unordered_map<int, int> prev_knapsacke
  unordered_map<pair<int, int>, int, PairHash> memo_td;

  int profit_topdown = knapsack_topdown(w, p, memo_td, size, w.size());
  cout << "Profit Topdown: " << profit_topdown << endl;

  vector<vector<int>> memo_bu(w.size() + 1, vector<int>(size + 1, 0));
  int profit_bottomup = knapsack_bottomup(w, p, memo_bu, size, w.size());
  cout << "Profit Bottomup: " << profit_bottomup << endl;

  int ii = w.size();
  int jj = size;

  for (int i = 0; i < w.size() + 1; i++) {
    for (int j = 0; j < size + 1; j++) {
      cout << memo_bu[i][j] << " ";
    }
    cout << endl;
  }

  while (ii > 0 and jj > 0) {
    if (memo_bu[ii][jj] != memo_bu[ii - 1][jj]) {
      jj -= w[ii - 1];
      cout << w[ii - 1] << " ";
    }
    ii--;
  }
  cout << endl;

  return 0;
}
