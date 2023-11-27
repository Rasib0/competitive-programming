#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // perfect shuffle  -> initial deck div in half
  //  two halves are perfectly interleaved
  //  ABCD EFGH -> AEBFCGDH outshuffle
  //  start from second half -> EAFBGCHD inshuffle
  //  in standard 52 card deck, only 8 outshuffle are needed deck returns to
  //  origonal order
  // for outshuffle -> first half (a) > second half
  // for inshuffle -. second hald  (b) > first half
  int n;
  string inout;

  cin >> n >> inout;

  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    v[i] = i;
  }

  vector<int> v_copy(n);
  copy(v.begin(), v.end(), v_copy.begin());

  int count = 0;
  bool should_break = false;

  if (inout == "out") {
    int a = n % 2 == 0 ? n / 2 : n / 2 + 1;

    while (true) {
      if (should_break)
        break;

      // outshuffle

      vector<int> temp(n);

      for (int i = 0; i < a; i++) {
        temp[2 * i] = v_copy[i];

        if (i != a - 1 or n % 2 == 0)
          temp[(2 * i) + 1] = v_copy[a + i];
      }

      v_copy = temp;

      if (v == v_copy) {
        should_break = true;
      }

      count++;
    }
  } else {
    int a = n / 2;

    while (true) {
      if (should_break)
        break;

      // inshuffle
      vector<int> temp(n);

      for (int i = 0; i < a; i++) {
        temp[2 * i] = v_copy[a + i];
        temp[(2 * i) + 1] = v_copy[i];
      }

      if (n % 2 != 0)
        temp[n - 1] = v_copy[n - 1];

      v_copy = temp;

      if (v == v_copy) {
        should_break = true;
      }

      count++;
    }
  }

  cout << count << endl;

  return 0;
}
