#include <iostream>
#include <vector>

using namespace std;

bool hasShipsLeft(const vector<vector<char>> &map) {
  for (const auto &row : map) {
    for (const auto &ship : row) {
      if (ship == '#') {
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
    bool game_over = false;

    int turn_count = 0;

    // ------------------- GAME LOOP ------------------- //
    while (turn_count < n) {

      if (game_over) {
        turn_count++;
        continue;
      }
      // player 1 turn to shoot
      while (player1_has_turn and turn_count < n) {

        cin >> x >> y;
        y = h - 1 - y;

        turn_count++;
        //cout << "Player 1 shoots at " << x << "," << -(y - h + 1) << endl;

        // if player1 hits, he may continue if more ships are left
        if (map2[y][x] == '#') {
          map2[y][x] = '_';

          if (not hasShipsLeft(map2)) {
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
        //cout << "Player 2 shoots at " << x << "," << -(y - h + 1) << endl;

        // if player2 hits, he gets another turn
        if (map1[y][x] == '#') {
          map1[y][x] = '_';
          // if  enemy has other ships left, player2 may continue
          if (not hasShipsLeft(map1)) {
            player1_has_turn = true;
          }

        } else {
          player1_has_turn = true;
        }
        if (not hasShipsLeft(map1) or not hasShipsLeft(map2)) {
          if (not player1_has_turn and not hasShipsLeft(map2)) {
            continue;
          }
          game_over = true;
          break;
        }
      }
    }

    if (hasShipsLeft(map1) and hasShipsLeft(map2)) {
      cout << "draw" << endl;
    } else if (hasShipsLeft(map1)) {
      cout << "player one wins" << endl;
    } else if (hasShipsLeft(map2)) {
      cout << "player two wins" << endl;
    } else {
      cout << "draw" << endl;
    }
  }

  return 0;
}
