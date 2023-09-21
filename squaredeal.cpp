#include <iostream>

using namespace std;

struct Rectangle {
  int width;
  int height;
} r1, r2, r3, fr1, fr2, fr3;

Rectangle flip(bool flag, int rec_number) {
  if (flag == 0) {
    switch (rec_number) {
    case 1:
      return r1;
      break;
    case 2:
      return r2;
      break;
    default:
      return r3;
    }
  } else {
    switch (rec_number) {
    case 1:
      return fr1;
      break;
    case 2:
      return fr2;
      break;
    default:
      return fr3;
    }
  }
}

bool nth_bit(int number, int n) { return (number & (1 << n)) >> n; }

int main() {
  cin >> r1.width >> r1.height >> r2.width >> r2.height >> r3.width >>
      r3.height;

  fr1.height = r1.width;
  fr1.width = r1.height;

  fr2.height = r2.width;
  fr2.width = r2.height;

  fr3.height = r3.width;
  fr3.width = r3.height;

  // 1.
  for (int i = 0; i < (1 << 3); i++) {
    int bit1 = nth_bit(i, 0);
    int bit2 = nth_bit(i, 1);
    int bit3 = nth_bit(i, 2);

    // 1
    if (flip(bit1, 1).height + flip(bit2, 2).height + flip(bit3, 3).height ==
            flip(bit1, 1).width &&
        flip(bit1, 1).width == flip(bit2, 2).width &&
        flip(bit2, 2).width == flip(bit3, 3).width) {
      // cout << "Case 1" << endl;
      cout << "YES" << endl;
      return 0;
    }

    // 2
    if (flip(bit1, 1).height + flip(bit2, 2).height ==
            flip(bit1, 1).width + flip(bit3, 3).width and
        (flip(bit1, 1).width + flip(bit3, 3).width == flip(bit2, 2).width or
         flip(bit1, 1).height + flip(bit2, 2).height == flip(bit3, 3).height)) {
      // cout << "Case 2" << endl;
      cout << "YES" << endl;
      return 0;
    }

    // 3
    if (flip(bit1, 1).height + flip(bit2, 2).height ==
            flip(bit2, 2).width + flip(bit3, 3).width and
        (flip(bit2, 2).width + flip(bit3, 3).width == flip(bit1, 1).width or
         flip(bit1, 1).height + flip(bit2, 2).height == flip(bit3, 3).height)) {
      // cout << "Case 3" << endl;
      cout << "YES" << endl;
      return 0;
    }

    // 4
    if (flip(bit2, 2).height + flip(bit3, 3).height ==
            flip(bit3, 3).width + flip(bit1, 1).width and
        (flip(bit1, 1).width + flip(bit3, 3).width == flip(bit2, 2).width or
         flip(bit3, 3).height + flip(bit2, 2).height == flip(bit1, 1).height)) {
      // cout << "Case 4" << endl;
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}
