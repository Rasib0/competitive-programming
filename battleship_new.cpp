#include <iostream>
#include <vector>

using namespace std;

bool hasShipsLeft(vector<vector<char>> &map) {
  for (auto row : map) {
    for (auto entry : row) {
      if (entry == '#') {
        return true;
      }
    }
  }
  return false;
}

int main() {
  size_t t;
  cin >> t;

  for (size_t i = 0; i < t; i++) {
    size_t w, h, n;
    cin >> w >> h >> n;

    vector<vector<char>> player2_ships(h, vector<char>(w));
    vector<vector<char>> player1_ships(h, vector<char>(w));
    vector<pair<size_t, size_t>> moves;

    for (size_t i = 0; i < h; i++) {
      for (size_t j = 0; j < w; j++) {
        cin >> player1_ships[i][j];
      }
    }

    for (size_t i = 0; i < h; i++) {
      for (size_t j = 0; j < w; j++) {
        cin >> player2_ships[i][j];
      }
    }

    for (size_t i = 0; i < n; i++) {
      size_t x, y;
      cin >> x >> y;
      moves.push_back(make_pair(x, y));
    }

    bool p1_turn = true;
    for (size_t i = 0; i < n; i++) {
      size_t x = moves[i].first;
      size_t y = moves[i].second;
      y = h - 1 - y;

      if (p1_turn) {
        cout << "Player 1 shoots at " << x << ", " << -(y + 1 - h) << endl;
        if (player2_ships[y][x] == '#') {
          player2_ships[y][x] = '_';

          if (!hasShipsLeft(player2_ships)) {
            p1_turn = false;
          }

        } else {
          p1_turn = false;
        }

      } else {
        cout << "Player 2 shoots at " << x << ", " << -(y + 1 - h) << endl;
        if (player1_ships[y][x] == '#') {
          player1_ships[y][x] = '_';

          if (!hasShipsLeft(player1_ships)) {
            p1_turn = true;
          }

        } else {
          p1_turn = true;
        }
      }

      if (not hasShipsLeft(player2_ships) or not hasShipsLeft(player1_ships)) {
        // don't end on a p1_turn
        if ((not p1_turn) and (not hasShipsLeft(player2_ships))) {
          continue;
        }
        break;
      }
    }

    bool a = hasShipsLeft(player1_ships);
    bool b = hasShipsLeft(player2_ships);

    if (a and b) {
      cout << "draw" << endl;
    } else if (a) {
      cout << "player one wins" << endl;
    } else if (b) {
      cout << "player two wins" << endl;
    } else {
      cout << "draw" << endl;
    }
  }
  return 0;
}
