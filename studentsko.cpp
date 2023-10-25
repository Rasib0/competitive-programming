#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define int long long int

using namespace std;

int32_t main() {
  int n, k;
  cin >> n >> k;

  map<int, int> m;
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    m[arr[i]] = 0;
  }

  int i = 0;
  for (auto &[key, e] : m) {
    m[key] = i / k;
    i++;
  }

  for (auto &x : arr) {
    x = m[x];
  }

  vector<int> LIS(n, 1);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[j] <= arr[i])
        LIS[i] = max(LIS[i], LIS[j] + 1);
    }
  }
  int maximum = *max_element(LIS.begin(), LIS.end());

  cout << n - maximum << endl;

  return 0;
}

// 0, 1, 2, 3, 4; k = 2
// 0, 0, 1, 1, 2, 2,
