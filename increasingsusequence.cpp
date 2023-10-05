#include <algorithm>
#include <iostream>
#include <vector>
#define int long long int

using namespace std;

bool b_is_earlier(vector<int> &a, vector<int> &b) {

  for (int i = 0; i < a.size(); i++) {
    if (a[i] < b[i]) {
      return false;
    }
    if (a[i] > b[i]) {
      return true;
    }
  }
  return true;
}

int32_t main() {
  while (true) {
    int n;
    cin >> n;

    if (n == 0) {
      break;
    }

    vector<int> v(n);
    vector<int> memo(n, 1);
    vector<vector<int>> paths(n, vector<int>());

    int maximum = 1;
    int maximum_index = 0;

    // for each entry in the memo store the lexographicaly smallest sequence
    // to get that index
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    for (int i = 0; i < n; i++) {

      paths[i].push_back(v[i]);

      for (int j = 0; j < i; j++) {

        if (memo[j] + 1 == maximum and b_is_earlier(paths[i], paths[j])) {
          maximum_index = i;
        }

        if (v[j] >= v[i]) {
          continue;
        }

        if (memo[j] + 1 == memo[i]) {
          if (b_is_earlier(paths[i], paths[j])) {
            paths[i].clear();

            for (auto &node : paths[j]) {
              paths[i].push_back(node);
            }

            paths[i].push_back(v[i]);
          }
        }

        if (memo[j] + 1 > memo[i]) {
          memo[i] = memo[j] + 1;

          if (memo[i] > maximum) {
            maximum = memo[i];
            maximum_index = i;
          }

          paths[i].clear();

          for (auto &node : paths[j]) {
            paths[i].push_back(node);
          }

          paths[i].push_back(v[i]);
        }
      }
    }

    cout << maximum << " ";

    for (auto &m : paths[maximum_index]) {
      cout << m << " ";
    }
    cout << endl;
  }

  return 0;
}
