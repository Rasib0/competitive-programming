#include <iostream>
#include <vector>

using namespace std;
int main() {
  int T, N;
  cin >> T >> N;

  vector<int> w(N);
  vector<int> p(N);
  vector<bool> used(N, false);

  vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0));
  for (int i = 0; i < N; i++) {
    cin >> w[i];
    p[i] = w[i]; // don't really need a seperate profit vector
  }

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= T; j++) {
      if (i == 0 or j == 0)
        dp[i][j] = 0;
      else if (w[i - 1] <= j) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + p[i - 1]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  int ii = N;
  int jj = T;
  // backtrack to find the solution set
  while (ii > 0 and jj > 0) {
    if (dp[ii][jj] != dp[ii - 1][jj]) {
      jj -= w[ii - 1];
      used[ii - 1] = true;
    }
    ii--;
  }

  // print the solution
  ii = 0;
  jj = 0;
  for (int i = 0; i < N; i++) {
    if (used[i]) {
      cout << ii << " ";
      ii += w[i];
    } else {
      cout << jj << " ";
      jj += w[i];
    }
  }

  cout << endl;

  return 0;
}
