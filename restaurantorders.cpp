#include <iostream>
#include <utility>
#include <vector>

#define endl "\n"
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0);
using namespace std;

// pair <prev, element>
void combination_sum(int T, vector<int> &v, vector<vector<pair<int, int>>> &dp,
                     vector<int> &count) {
  for (int i = 0; i < v.size(); i++) {
    int c = v[i];
    for (int j = c; j <= T; j++) {

      if (j == c) {
        dp[j].push_back({-1, i});
        count[j]++;
      }

      if (count[j - c] > 1) {
        count[j] = 2;
      } else {
        // for (auto comb : dp[j - c]) {
        for (int k = 0; k < dp[j - c].size(); k++) {
          dp[j].push_back({j - c, i});
          count[j]++;
        }
      }
    }
  }
}

int32_t main() {
  int N;
  cin >> N;
  vector<int> prices(N);
  for (int i = 0; i < N; i++) {
    cin >> prices[i];
  }

  int M;
  cin >> M;
  vector<int> t(M);
  int max_target = 0;
  for (int i = 0; i < M; i++) {
    cin >> t[i];
    if (max_target < t[i]) {
      max_target = t[i];
    }
  }

  vector<int> count(max_target + 1);
  vector<vector<pair<int, int>>> dp(max_target + 1, vector<pair<int, int>>());

  combination_sum(max_target, prices, dp, count);

  for (auto target : t) {
    if (count[target] == 0) {
      cout << "Impossible" << endl;
    } else if (count[target] > 1) {
      cout << "Ambiguous" << endl;
    } else {
      auto pair = dp[target][0];
      vector<int> ans;
      ans.push_back(pair.second);

      while (pair.first != -1 and pair.second != 0) {
        pair = dp[pair.first][0];
        ans.push_back(pair.second);
      }

      for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] + 1 << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
