#include <iostream>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  if (x == 0 && y == 1) {
    cout << "ALL GOOD" << endl;
  } else if (y == 1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    double ans = x / (1.0 - y);
    cout.precision(9);
    cout << fixed << ans << endl;
  }
  return 0;
}
