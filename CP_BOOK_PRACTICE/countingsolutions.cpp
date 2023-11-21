#include <iostream>
#include <vector>
using namespace std;

int countingsum(int x, vector<int> &coins, vector<int> &memo) {
  if (x < 0)
    return 0;
  if (x == 0)
    return 1;
  if (memo[x] != -1)
    return memo[x];

  int sum = 0;
  for (auto &c : coins) {
    sum += countingsum(x - c, coins, memo);
  }
  memo[x] = sum;
  return sum;
}

int main() {
  auto x = 5;
  vector<int> coins = {1, 3, 4};
  vector<int> memo(6, -1);
  cout << countingsum(x, coins, memo) << endl;
  // total number of ways to produce a sum x using the coins;
  // solve(x) = solve(x-1) + solve(x - 3) + solve(x - 4)
  return 0;
}
