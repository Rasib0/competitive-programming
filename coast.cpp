#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> coast(N, vector<int>(M, 0));

  for (auto &r : coast) {
    for (auto &e : r) {
      cin >> e;
    }
  }

  for (int i = 0; i < coast.size(); i++) {
    for (int j = 0; j < coast[0].size(); j++) {
    }
  }

  cout << "Hello world!" << endl;
  return 0;
}
