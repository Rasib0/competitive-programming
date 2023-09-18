#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int test_cases{};
  cin >> test_cases;

  for (int t = 0; t < test_cases; t++) {
    int n;
    cin >> n;

    map<int, int> cards;
    size_t pointer = 0;

    for (int i = 1; i <= n; i++) {
    }

    for (auto &[key, value] : cards) {
      cout << key << ": " << value << endl;
    }
  }

  return 0;
}

// a, b, c
//
