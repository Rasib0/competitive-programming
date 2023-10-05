#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#define int long long int
using namespace std;

int count_flies(vector<vector<int>> &grid, size_t r, size_t c, size_t K) {
  int sum = 0;

  for (int i = r + 1; i < r + K - 1; i++) {
    for (int j = c + 1; j < c + K - 1; j++) {
      sum += grid[i][j];
    }
  }

  return sum;
}

int32_t main() {
  int rows, cols, K;
  // R -> Rows
  // S -> Columns
  // K -> length of side of racket
  cin >> rows >> cols >> K;
  vector<vector<int>> grid(rows, vector<int>(cols, 0));

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      char pixel;
      cin >> pixel;
      grid[i][j] = pixel == '*' ? 1 : 0;
    }
  }

  int max_value = 0;
  pair<size_t, size_t> max_index;

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {

      if ((r + K - 1) >= rows || (c + K - 1) >= cols) {
        continue;
      }

      int curr = count_flies(grid, r, c, K);

      if (curr > max_value) {
        max_value = curr;
        max_index = {r, c};
      }
    }
  }

  cout << max_value << endl;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {

      if (i == max_index.first and j == max_index.second) {
        cout << "+";
      } else if (i == max_index.first + K - 1 and
                 j == max_index.second + K - 1) {
        cout << "+";
      } else if (i == max_index.first + K - 1 and j == max_index.second) {
        cout << "+";
      } else if (i == max_index.first and j == max_index.second + K - 1) {
        cout << "+";
      } else if (j == max_index.second or j == max_index.second + K - 1) {
        if (i >= max_index.first and i <= max_index.first + K - 1) {
          cout << "|";
        } else {
          if (grid[i][j] == 1) {
            cout << '*';
          } else {
            cout << '.';
          }
        }
      } else if (i == max_index.first or i == max_index.first + K - 1) {
        if (j >= max_index.second and j <= max_index.second + K - 1) {
          cout << "-";
        } else {
          if (grid[i][j] == 1) {
            cout << '*';
          } else {
            cout << '.';
          }
        }
      } else {
        if (grid[i][j] == 1) {
          cout << '*';
        } else {
          cout << '.';
        }
      }
    }
    cout << endl;
  }
  return 0;
}
