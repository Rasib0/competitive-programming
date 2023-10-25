#include <iostream>
#include <unordered_map>
#include <vector>
#define int long long int

using namespace std;

int32_t main() {
  int testcases;
  cin >> testcases;

  for (int t = 0; t < testcases; t++) {
    int N;
    cin >> N;
    bool found = false;
    vector<int> v(N);
    unordered_map<int, int> sums; // sum, bits

    for (auto &i : v) {
      cin >> i;
    }

    cout << "Case #" << t + 1 << ": " << endl;

    for (int i = 1; i < (1LL << N); i++) {
      int sum = 0;
      for (int j = 0; j < N; j++) {
        if (i & (1LL << j)) {
          sum += v[j];
        }
      }

      if (sums.find(sum) != sums.end()) {
        found = true;
        for (int j = 0; j < N; j++) {
          if (sums[sum] & (1LL << j)) {
            cout << v[j] << " ";
          }
        }
        cout << endl;
        for (int j = 0; j < N; j++) {
          if (i & (1LL << j)) {
            cout << v[j] << " ";
          }
        }
        cout << endl;
        break;
      }

      sums[sum] = i;
    }

    if (!found)
      cout << "Impossible" << endl;
  }

  return 0;
}
