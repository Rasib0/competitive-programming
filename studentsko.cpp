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
  // Too slow
  // vector<int> LIS(n, 1);

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < i; j++) {
  //     if (arr[j] <= arr[i])
  //       LIS[i] = max(LIS[i], LIS[j] + 1);
  //   }
  // }
  // int maximum = *max_element(LIS.begin(), LIS.end());
  vector<int> lis;
  lis.push_back(arr[0]);

  for (int i = 1; i < n; i++) {
    int val = arr[i];

    // make a new pile
    if (val >= lis.back()) {
      lis.push_back(val);
    } else {
      // find the pile to put it in i.e. the pile with the smallest top card
      // arr[i] > val
      auto it = upper_bound(lis.begin(), lis.end(), val);
      *it = val;
    }
  }
  cout << n - lis.size() << endl;
  return 0;
}
