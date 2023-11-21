#include <array>
#include <bitset>
#include <iostream>
#include <vector>
#define endl '\n'
#define ios ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
  ios;
  int test_cases;
  cin >> test_cases;
  test_cases = 3000;

  array<int, 5000> arr;
  // 4
  // 1 2 3 4
  // 1 3 4 2

  for (int t = 0; t < test_cases; t++) {
    int p = t;

    vector<bool> isFilled(p, false);
    int fill_c = 0;
    int skip_count = 0;
    int idx = 0;

    while (fill_c != p) {

      if (isFilled[idx]) {
        idx = (idx + 1) % p; // if filled go to next
        continue;
      }

      isFilled[idx] = true;
      fill_c++;
      skip_count++; // every iteration we go to increasingly more steps

      for (int i = 0; i < skip_count; i++) {
        idx = (idx + 1) % p;
        while (isFilled[idx] and fill_c != p) {
          idx = (idx + 1) % p;
        }
      }
      idx = (idx + 1) % p;
    }

    arr[t] = idx;
  }

  for (int i = 0; i < test_cases; i++) {
    cout << "[" << arr[i] << ", "
         << " -1]";
  }

  return 0;
}
