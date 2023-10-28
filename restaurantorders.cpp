#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <set>
#include <vector>

#define int long long int
#define endl "\n"
#define vec vector
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0);

// TODO
using namespace std;

void combination_sum(int T, int index, vector<int> &v, set<vector<int>> &paths,
                     vector<int> &path) {
  if (T < 0) {
    return;
  }

  if (paths.size() > 1) {
    return;
  }

  if (T == 0) {
    sort(path.begin(), path.end());
    paths.insert(path);
    return;
  }

  for (int i = index; i < v.size(); i++) {
    path.push_back(i + 1);
    vector<int> path_copy(path);
    combination_sum(T - v[i], i, v, paths, path_copy);
    path.pop_back();
  }
}

int32_t main() {
  IOS;

  // input
  int N;
  cin >> N;
  vec<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  int M;
  cin >> M;
  vec<int> t(M);
  for (int i = 0; i < M; i++) {
    cin >> t[i];
  }

  // solve for each testcases
  for (int i = 0; i < M; i++) {
    vec<int> path_dummy;

    set<vec<int>> paths; // outputs all the paths with maximum profit
    combination_sum(t[i], 0, v, paths, path_dummy);

    if (paths.size() == 0)
      cout << "Impossible" << endl;
    else if (paths.size() > 1)
      cout << "Ambiguous" << endl;
    else {
      for (auto x : *paths.begin()) {
        cout << x << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
