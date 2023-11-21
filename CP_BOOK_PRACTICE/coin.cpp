#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> prev(n + 1);
  vector<int> counts(n + 1);
  counts[0] = 0;

  vector<int> coins = {1, 3, 4};

  for (int x = 1; x <= n; x++) {
    counts[x] = INT32_MAX;
    for (auto &c : coins) {
      if (x - c >= 0 and counts[x - c] + 1 < counts[x]) {
        counts[x] = counts[x - c] + 1;
        // when setting the count, note the first coin that you took
        prev[x] = c;
      }
    }
  }

  for (auto &c : counts) {
    cout << c << " ";
  }

  cout << endl;

  cout << "How to make: " << endl;

  while (n > 0) {
    cout << prev[n];
    n = n - prev[n];
  }

  cout << endl;

  return 0;
}
