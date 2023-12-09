#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> get_paths(vector<vector<int>> &grid) {
  vector<vector<int>> paths;
  vector<int> path;
  int i = 0, j = 0;
  while (i < grid.size() && j < grid[0].size()) {
    path.push_back(grid[i][j]);
    if (i == grid.size() - 1) {
      while (j < grid[0].size()) {
        path.push_back(grid[i][j]);
        j++;
      }
    }
    if (j == grid[0].size() - 1) {
      while (i < grid.size()) {
        path.push_back(grid[i][j]);
        i++;
      }
    }
    i++;
    j++;
  }
  return paths;
}
int main() {
  vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // list all the paths from the top left to the bottom right
  // only move down or right
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
