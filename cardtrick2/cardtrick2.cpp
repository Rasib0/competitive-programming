#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void increment_pointer_legally(size_t &pointer, vector<int> &cards) {
  // increment
  pointer = (pointer + 1) % cards.size();

  // if filled goto next empty
  while (cards[pointer] != 0) {
    pointer = (pointer + 1) % cards.size();
  }
}

int main() {
  int test_cases{};
  cin >> test_cases;

  for (int t = 0; t < test_cases; t++) {
    int n;
    cin >> n;

    vector<int> cards(n);

    size_t pointer = 0;

    for (int i = 1; i <= n; i++) {

      // move i cards to the bottom
      for (int j = 0; j < i; j++) {
        increment_pointer_legally(pointer, cards);
      }

      cards[pointer] = i;

      // if all cards are filled, break
      if (i == n) {
        break;
      }

      increment_pointer_legally(pointer, cards);
    }

    for (auto &card : cards) {
      cout << card << " ";
    }
    cout << endl;
  }

  return 0;
}
