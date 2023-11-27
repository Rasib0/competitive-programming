#include <iostream>
#include <vector>

#define int long long int
using namespace std;

int32_t main() {
  int test_cases; // 1 <= n <= 20
  cin >> test_cases;

  for (int t = 0; t < test_cases; t++) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);

    for (auto &entry : v) {
      cin >> entry;
    }

    int prev_m_index = -1;

    int sum = 0;
    int best = 0;

    // Problem is you always need to have 1 m

    for (int i = 0; i < n; i++) {

      if (v[i] < m) {
        sum = 0;
        prev_m_index = -1;
        continue;
      }

      if (prev_m_index != -1 and v[i] == m) {
        sum = 0;
        i = prev_m_index;
        prev_m_index = -1;
        continue;
      }

      if (v[i] == m) {
        prev_m_index = i;
      }

      sum = sum + v[i] > v[i] ? sum + v[i] : v[i];

      if (prev_m_index != -1) {
        best = best > sum ? best : sum;
      }
    }

    cout << best << endl;
  }

  return 0;
}
