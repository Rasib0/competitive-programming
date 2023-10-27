#include <iostream>
#include <vector>

using namespace std;

int main() {
  while (true) {
    int N, k;
    cin >> N >> k;

    if (N == 0 and k == 0)
      break;

    vector<vector<int>> gallery(2, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
      cin >> gallery[0][N];
      cin >> gallery[1][N];
    }

    for (int i = 0; i < N; i++) {
    }
  }

  return 0;
}
