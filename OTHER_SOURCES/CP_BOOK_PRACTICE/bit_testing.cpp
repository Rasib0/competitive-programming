#include <iostream>
using namespace std;

int main() {
  int b = 0;
  int x = (1 >> 3) | (1 | 4) | (1 << 8);

  // generate all subsets of {3, 4, 8}
  // One way to generate all subsets is to loop over 2^size
  do {
    cout << b << endl;
  } while (b = ((b - x) & x));
  return 0;
}
