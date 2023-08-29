#include <iostream>
#include <vector>

using namespace std;

bool vector_contains(const vector<vector<char>> &map, char x) {
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
  size_t test_cases;
  cin >> test_cases;

  for (size_t t = 0; t < test_cases; t++) {
    bool map2_isempty = false;
    bool map1_isempty = false;
    int w, h, n;
    cin >> w >> h >> n;
    // cout << "New w: " << w << endl;
    // cout << "New h: " << h << endl;
    // cout << "New n: " << n << endl;

    vector<vector<char>> map1(h, vector<char>(w));

    // Read the maps for player 1
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> map1[i][j];
      }
    }

    vector<vector<char>> map2(h, vector<char>(w));

    // Read the maps for player 2
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> map2[i][j];
      }
    }

    size_t x, y;

    bool player1_has_turn = true; // player1's turn

    int turn_count = 0;

    // ------------------- GAME LOOP ------------------- //
    while (turn_count < n) {

      // player 1 turn to shoot
      while (player1_has_turn and turn_count < n) {

        cin >> x >> y;
        y = h - 1 - y;

        turn_count++;
        // cout << "Player 1 shoots at " << x << "," << -(y - h + 1) << endl;

        // if player1 hits, he may continue if more ships are left
        if (map2[y][x] == '#') {
          map2[y][x] = '_';

          if (not vector_contains(map2, '#')) {
            map2_isempty = true;
            player1_has_turn = false;
          }

        } else {
          player1_has_turn = false;
        }
      }

      // player 2 turn to shoot
      while (not player1_has_turn and turn_count < n) {

        cin >> x >> y;
        y = h - 1 - y;

        turn_count++;
        // cout << "Player 2 shoots at " << x << "," << -(y - h + 1) << endl;

        // if player2 hits, he gets another turn
        if (map1[y][x] == '#') {
          map1[y][x] = '_';
          // if  enemy has other ships left, player2 may continue
          if (not vector_contains(map1, '#')) {
            map1_isempty = true;
            player1_has_turn = true;
          }

        } else {
          player1_has_turn = true;
        }
        if (map2_isempty or map1_isempty) {
          if (not player1_has_turn and map2_isempty) {
            continue;
          }
          break;
        }
      }
    }

    if (map2_isempty and map1_isempty) {
      cout << "draw" << endl;
    } else if (map2_isempty) {
      cout << "player one wins" << endl;
    } else if (map1_isempty) {
      cout << "player two wins" << endl;
    } else {
      cout << "draw" << endl;
    }
  }

  return 0;
}
