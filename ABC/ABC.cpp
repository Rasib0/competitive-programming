#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> triplet;
  triplet.push_back(a);
  triplet.push_back(b);
  triplet.push_back(c);

  sort(triplet.begin(), triplet.end());
  char character;

  while (cin >> character) {
    if (character == 'C') {
      cout << triplet[2];
    } else if (character == 'A') {
      cout << triplet[0];
    } else {
      cout << triplet[1];
    }
    cout << " ";
  }

  cout << endl;
  return 0;
}
