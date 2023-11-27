#include <iostream>

using namespace std;

// sum of final scores
// abs diff between the two scores

int main() {
  int n, s, d;
  cin >> n;

  // a + b = 20
  // a - b = 20  -- case 1
  // b - a = 20 -- case 2
  // either way the number is a multiple of 2!

  for (int i = 0; i < n; i++) {
    cin >> s >> d;

    if ((d > s) || ((s + d) % 2 != 0)) {
      cout << "impossible" << endl;
      continue;
    }

    int a = (s + d) / 2;
    int b = a - d;

    if (a > b) {
      cout << a << ' ' << b << endl;
    } else {
      cout << b << ' ' << a << endl;
    }
  }

  return 0;
}
