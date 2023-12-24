#include <iostream>
#include <vector>

/// Edit distance: find the minimum numbers of edits to convert str1 to str2
// 1. Insert a character
// 2. Delete a character
// 3. Replace a character
using namespace std;
int edit_distance_topdown(string &s1, string &s2, vector<vector<int>> &memo,
                          int m, int n) {
  if (m == 0)
    return n;
  if (n == 0)
    return m;
  if (memo[m][n] != -1)
    return memo[m][n];

  if (s1[m - 1] == s2[n - 1]) {
    memo[m][n] = edit_distance_topdown(s1, s2, memo, m - 1, n - 1);
    return memo[m][n];
  }

  memo[m][n] = min(min(1 + edit_distance_topdown(s1, s2, memo, m, n - 1),
                       1 + edit_distance_topdown(s1, s2, memo, m - 1, n)),
                   1 + edit_distance_topdown(s1, s2, memo, m - 1, n - 1));
  return memo[m][n];
}

int edit_distance_bottomup(string &s1, string &s2) {

  int m = s1.size();
  int n = s2.size();

  int dp[m + 1][n + 1];

  for (int i = 0; i < m + 1; i++) {
    for (int j = 0; j < n + 1; j++) {
      if (i == 0) {
        dp[i][j] = j;
      } else if (j == 0) {
        dp[i][j] = i;
      } else if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
      }
    }
  }
  return dp[m][n];
}

int lcs_bottomup(string &text1, string &text2) {
  int m = text1.size();
  int n = text2.size();

  int dp[m + 1][n + 1]; // why size +1? Because we added an extra row+col

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0)
        dp[i][j] = 0;
      else if (j == 0)
        dp[i][j] = 0;
      else if (text1[i - 1] == text2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else {
        dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
      }
    }
  }

  return dp[m][n];
}

int main() {

  string s1 = "sunday";
  string s2 = "saturday";

  vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));

  cout << edit_distance_topdown(s1, s2, memo, s1.size(), s2.size()) << endl;
  cout << edit_distance_bottomup(s1, s2) << endl;
  cout << "Expected: 3" << endl;

  cout << "LCS: " << lcs_bottomup(s1, s2) << endl;

  for (auto &row : memo) {
    for (auto &col : row) {
      cout << col << " ";
    }
    cout << endl;
  }

  return 0;
}
