#include <iostream>
#include <vector>

using namespace std;

int main() {
  string input;
  cin >> input;
  vector<int> cups = {1, 0, 0};

  for (auto &ch : input) {
    if (ch == 'A') {
      int temp = cups[0];
      cups[0] = cups[1];
      cups[1] = temp;
    }

    else if (ch == 'B') {
      int temp = cups[1];
      cups[1] = cups[2];
      cups[2] = temp;
    }

    else {
      int temp = cups[0];
      cups[0] = cups[2];
      cups[2] = temp;
    }
  }

  for (int i = 0; i < 3; i++) {
    if (cups[i] == 1) {
      cout << i + 1;
      break;
    }
  }

  return 0;
}
