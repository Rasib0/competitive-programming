#include <iostream>
#include <vector>

using namespace std;

int main() {
  // when zoo bell rings, the lowest 1 turns into 0
  // all 0s below that point turn into 1
  int n;
  cin >> n;

  long long input_string = 0;
  char input_char{};
  cin >> input_char;

  if (input_char == 'Z') {
    input_string = 0;
  } else {
    input_string = 1;
  }

  for (int i = 0; i < n - 1; i++) {
    char input_char{};
    cin >> input_char;

    if (input_char == 'Z') {
      input_string = input_string << 1;

    } else {
      input_string = (input_string << 1) + 1;
    }
  }

  cout << input_string << endl;

  return 0;
}

// 1010100
// ouput: 1010011
// operation: -1
