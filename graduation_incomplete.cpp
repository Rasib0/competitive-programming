#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> grid(n);

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[j][i];
    }
  }

  map<char, int> class_to_color;
  vector<char> assigned(k);

  int color = 1;
  // for each class, assgin a color to all class in the same row
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      // if this row doesn't contained a assigned class
      // assign this class a new color
      if (class_to_color.find(grid[i][j]) == class_to_color.end()) {
        class_to_color[grid[i][j]] = color;
        assigned.push_back(grid[i][j]);
        color++;
      }
    }
  }

  cout << color << endl;
  return 0;
}
