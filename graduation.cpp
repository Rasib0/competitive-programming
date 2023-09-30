#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main() {

  int n, // rows
      m, // columns
      k; // number of classes

  cin >> n >> m >> k;

  vector<vector<char>> grid(m, vector<char>(n));

  for (int col = 0; col < n; ++col) {
    for (int row = 0; row < m; ++row) {
      cin >> grid[row][col];
    }
  }

  map<char, int> classes;
  queue<char> new_assigned_classes;
  vector<char> visited;

  vector<bool> rows_assigned(m, false);
  int curr_color = 0;

  for (int row = 0; row < m; ++row) {
    if (rows_assigned[row]) {
      continue;
    }

    rows_assigned[row] = true;

    curr_color++;

    char curr_class = grid[row][0];

    for (int col = 0; col < n; col++) {
      classes[grid[row][col]] = curr_color;

      if (find(visited.begin(), visited.end(), grid[row][col]) ==
          visited.end()) {
        visited.push_back(grid[row][col]);
        new_assigned_classes.push(grid[row][col]);
      }
    }

    while (!new_assigned_classes.empty()) {

      char cl = new_assigned_classes.front();

      new_assigned_classes.pop();

      for (int row2 = 0; row2 < m; row2++) {
        if (rows_assigned[row2]) {
          continue;
        }

        auto class_iter = find(grid[row2].begin(), grid[row2].end(), cl);

        if (class_iter != grid[row2].end()) {
          rows_assigned[row2] = true;
          int color = classes[*class_iter];
          // assign the whole row this color
          for (int col = 0; col < n; col++) {
            if (find(visited.begin(), visited.end(), grid[row2][col]) ==
                visited.end()) {
              new_assigned_classes.push(grid[row2][col]);
            }
            classes[grid[row2][col]] = color;
          }
        }
      }
    }
  }

  cout << curr_color << endl;

  return 0;
}
