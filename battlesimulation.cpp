#include <iostream>
using namespace std;

// Algorithm: Brute Force
// Time Complexity: O(n)
// Space Complexity: O(n)
// The loop iterates over the string and check 3 characters
// if three characters are different, then we C to the output string
int main() {
  string input;
  string output;

  cin >> input;
  int length = input.length();
  bool last_three_flag[3];
  // first two characters
  for (int i = 2; i < length; i++) {
    last_three_flag[0] = false;
    last_three_flag[1] = false;
    last_three_flag[2] = false;

    for (int j = 0; j < 3; j++) {

      if (input[i - j] == 'R') {
        last_three_flag[0] = true;
      }

      if (input[i - j] == 'B') {
        last_three_flag[1] = true;
      }

      if (input[i - j] == 'L') {
        last_three_flag[2] = true;
      }
    }

    if (last_three_flag[0] && last_three_flag[1] && last_three_flag[2]) {
      printf("C");
      last_three_flag[0] = false;
      last_three_flag[1] = false;
      last_three_flag[2] = false;

      i += 2;
    }

    if (input[i] == 'R') {
      printf("S");
    } else if (input[i] == 'B') {
      printf("K");
    } else if (input[i] == 'L') {
      printf("H");
    }
  }

  return 0;
}
