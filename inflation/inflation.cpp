#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <unordered_map>
#include <vector>

#define int long long int

using namespace std;

// Lesson Learned: Don't store the list in the map when you can store the count

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  cin >> q;
  cin.ignore();

  int totalSum = accumulate(v.begin(), v.end(), 0LL);
  int offset = 0LL;

  unordered_map<int, int> m;

  for (int i = 0; i < n; i++) {
    m[v[i]]++;
  }

  for (int i = 0; i < q; i++) {
    string line;
    getline(cin, line);
    istringstream iss(line);

    string operation;
    iss >> operation;

    if (operation == "INFLATION") {
      int x;
      iss >> x;
      totalSum += x * n;
      offset += x;

    } else {
      int x, y;
      iss >> x >> y;

      if (x == y) {
        cout << totalSum << endl;
        continue;
      }

      m[y - offset] += m[x - offset];
      totalSum += (y - x) * m[x - offset];
      m[x - offset] = 0;
    }

    cout << totalSum << endl;
  }

  return 0;
}
