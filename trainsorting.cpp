#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#define int long long int
using namespace std;

int32_t main() {

  int n;
  cin >> n;

  vector<int> LIS_start_at(n, 1); // stores the length of the longest increasing
  vector<int> LDS_start_at(n, 1); // stores the length of the longest decreasing
                                  // subsequence starting at index i
  vector<int> w(n);               // stores the weights of the cars
  int answer = 0;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = i + 1; j <= n - 1; j++) {

      if (w[j] > w[i]) {
        if (LIS_start_at[i] < LIS_start_at[j] + 1)
          LIS_start_at[i] = LIS_start_at[j] + 1;
      } else {
        if (LDS_start_at[i] < LDS_start_at[j] + 1)
          LDS_start_at[i] = LDS_start_at[j] + 1;
      }
    }
    answer = std::max(answer, LIS_start_at[i] + LDS_start_at[i] - 1);
  }

  for (auto &mem : LIS_start_at)
    cout << mem << " ";
  cout << endl;
  for (auto &mem : LDS_start_at)
    cout << mem << " ";
  cout << endl;

  //  100, 1, 50, 2
  //  100
  //  100, 50, 2
  //  1 50
  //  100, 50, 2
  //  100, 50, 2
  //  100
  //  100, 50 2
  //

  cout << answer << endl;
  return 0;
}
