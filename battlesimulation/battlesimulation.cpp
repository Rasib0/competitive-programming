#include <iostream>
#include <unordered_map>

using namespace std;

// Algorithm: Brute Force
// Time Complexity: O(n)
// Space Complexity: O(n)
// The loop iterates over the string and check 3 characters
// if three characters are different, then we C to the output string
int main() {
  string input;
  string output;

  unordered_map<char, char> moves_map;

  moves_map['R'] = 'S';
  moves_map['B'] = 'K';
  moves_map['L'] = 'H';

  cin >> input;

  for (int i = 0; i < input.size(); i++) {

    // if we can't see the next next character
    if (i + 2 >= input.size()) {
      // print the remaining strings
      for (int j = i; j < input.size(); j++) {
        printf("%c", moves_map[input[j]]);
      }
      break;
    }
    // if the three moves are distinct
    if (input[i] != input[i + 1] and input[i + 1] != input[i + 2] and
        input[i] != input[i + 2]) {
      printf("C");
      i += 2;
    } else {
      printf("%c", moves_map[input[i]]);
    }
  }
  printf("\n");
  return 0;
}
