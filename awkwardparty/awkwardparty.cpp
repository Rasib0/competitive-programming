#include <iostream>
#include <map>

using namespace std;
// awkwardness level = minimum number of seats separating any two guests
// speaking the same language if no two people speak the same language then
// awkwardness level is 0
int main() {
  int n;
  cin >> n; // number of guests
            //
  int min_distance{n};

  map<int, int> point_a;
  map<int, int> point_b;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (point_a.count(x) and point_b.count(x)) {
      point_a[x] = i;
    } else if (point_a.count(x)) {
      point_b[x] = i;

    } else {
      point_a[x] = i;
    }

    if (point_a.count(x) and point_b.count(x)) {
      int distance_between = abs(point_a[x] - point_b[x]);
      if (distance_between < min_distance) {
        min_distance = distance_between;
      }
    }
  }

  cout << min_distance << endl;

  return 0;
}
