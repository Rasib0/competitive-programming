#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m; // paint can sizes
            // number of colors joe needs
  cin >> n >> m;

  vector<int> can_sizes(n);
  vector<int> needs(m);

  for (int i = 0; i < n; i++) {
    cin >> can_sizes[i];
  }

  long long wasted = 0;

  sort(can_sizes.begin(), can_sizes.end());

  for (int i = 0; i < m; i++) {
    int need;
    cin >> need;

    int lo = 0;
    int hi = n;

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (need == can_sizes[mid]) {
        lo = mid;
        break;
      } else if (need > can_sizes[mid]) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    wasted += can_sizes[lo] - need;
  }

  cout << wasted << endl;

  return 0;
}
