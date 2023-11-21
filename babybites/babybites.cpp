#include <iostream>

using namespace std;
int main() {
  // first line contains an integer n (1 < n < 1000)
  // second line contains n space-separated words spoken by Arild
  // i'th of which is either a non-negative integer
  int count;
  cin >> count;

  bool makesSense = true;

  for (int i = 1; i <= count; ++i) {
    string word;
    cin >> word;

    if (word != "mumble") {
      int spokenNumber = stoi(word);
      if (spokenNumber != i) {
        makesSense = false;
        break;
      }
    }
  }

  if (makesSense) {
    cout << "makes sense" << endl;
  } else {
    cout << "something is fishy" << endl;
  }

  return 0;
}
