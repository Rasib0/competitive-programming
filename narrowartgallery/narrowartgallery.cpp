#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// prev 0 = left
// prev 1 = right
// prev 2 = none
int subroutine(vector<int> &row1, vector<int> &row2, int prev, int N, int k,
               vector<vector<vector<int>>> &dp) {
  if (k == 0)
    return 0;
  if (dp[N][k][prev] != -1) {
    return dp[N][k][prev];
  }
  if (N == 0)
    return numeric_limits<int>::max() / 2;

  switch (prev) {
  case 0:
    dp[N][k][prev] =
        min(row1[N - 1] + subroutine(row1, row2, 0, N - 1, k - 1, dp),
            subroutine(row1, row2, 2, N - 1, k, dp));
    break;
  case 1:
    dp[N][k][prev] =
        min(row2[N - 1] + subroutine(row1, row2, 1, N - 1, k - 1, dp),
            subroutine(row1, row2, 2, N - 1, k, dp));
    break;
  case 2:
    dp[N][k][prev] =
        min(min(row1[N - 1] + subroutine(row1, row2, 0, N - 1, k - 1, dp),
                row2[N - 1] + subroutine(row1, row2, 1, N - 1, k - 1, dp)),
            subroutine(row1, row2, 2, N - 1, k, dp));
    break;
  }
  return dp[N][k][prev];
}

int main() {
  int N, k;
  cin >> N >> k;

  vector<int> row1(N);
  vector<int> row2(N);

  vector<vector<vector<int>>> dp(
      N + 1, vector<vector<int>>(k + 1, vector<int>(3, -1)));

  int sum = 0;

  for (int i = 0; i < N; i++) {
    cin >> row1[i];
    cin >> row2[i];
    sum = sum + row1[i] + row2[i];
  }

  cout << sum - subroutine(row1, row2, 0, N, k, dp) << endl;

  return 0;
}
