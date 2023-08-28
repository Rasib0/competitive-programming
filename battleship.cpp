#include <iostream>
#include <vector>

using namespace std;

bool contains(const vector<vector<char>> &map, char x) {
  for (const auto &row : map) {
    for (const auto &ship : row) {
      if (ship == x) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int test_cases;
  int w, h, n;

  cin >> test_cases;

  for (int t = 0; t < test_cases; t++) {
    cin >> w >> h >> n;

    vector<vector<char>> player1_map(h, vector<char>(w));

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> player1_map[i][j];
      }
    }

    vector<vector<char>> player2_map(h, vector<char>(w));

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> player2_map[i][j];
      }
    }

    size_t x, y;
    for (int i = 0; i < n; i++) {

      cin >> x >> y;
      y = h - 1 - y;

      player1_map[y][x] = '_';
      player2_map[y][x] = '_';

      if (!contains(player1_map, '#')) {
        cout << "player 2 wins" << endl;
        break;
      }

      if (!contains(player2_map, '#')) {
        cout << "player 1 wins" << endl;
        break;
      }
    }
  }
  return 0;
}
