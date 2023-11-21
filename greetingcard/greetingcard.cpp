#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

struct PairHash {
  template <typename T1, typename T2>
  auto operator()(const pair<T1, T2> &p) const -> size_t {
    return (hash<T1>{}(p.first) << 32) | hash<T2>{}(p.second);
  }
};

int main() {
  int n;
  cin >> n;

  int num_of_lines{}; // ouput
  unordered_set<pair<int, int>, PairHash> coordinates;

  // stores all the input points into the coordinates vector
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    coordinates.insert({x, y});
  }

  // calculate the integer offsets x and y that are 2018 units apart from  an
  // arbitrary integer point x^2 + y^2 = 2018^2
  // int r = 2018;
  // // offset-x, offset-y
  vector<pair<int, int>> offsets;
  // for (int i = -r; i <= r; i++) {
  //   for (int j = -r; j <= r; j++) {
  //     int sum = i * i + j * j;
  //     if (sum == 2018 * 2018) {
  //       offsets.push_back({i, j});
  //     }
  //   }
  // }
  offsets = {
      {-2018, 0},   {-1680, -1118}, {-1680, 1118}, {-1118, -1680},
      {0, -2018},   {-1118, 1680},  {0, 2018},     {1118, -1680},
      {1118, 1680}, {1680, -1118},  {1680, 1118},  {2018, 0},
  };

  // for every pair of points check if neighbors => TOO SLOW!
  // put the coordinates in a hash, check if possible neighbor is in hash

  for (const auto &coordinate : coordinates) {
    for (const auto &[delta_x, delta_y] : offsets) {

      const auto &[x, y]{coordinate};
      const pair neightbour{x + delta_x, y + delta_y};

      if (coordinates.count(neightbour) > 0) {
        cout << num_of_lines;
        num_of_lines++;
      }
    }
  }

  std::cout << num_of_lines / 2 << endl;
  return 0;
}
