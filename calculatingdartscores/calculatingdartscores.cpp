#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int target;
  cin >> target;

  for (int i = 0; i <= 20; i++) {
    for (int j = 0; j <= 20; j++) {
      for (int k = 0; k <= 20; k++) {
        for (int a = 0; a <= 3; a++) {
          for (int b = 0; b <= 3; b++) {
            for (int c = 0; c <= 3; c++) {
              if (a * i + b * j + c * k == target) {
                vector<pair<int, int>> things = {{a, i}, {b, j}, {c, k}};

                for (auto &[times, score] : things) {
                  switch (times) {
                  case 0:
                    break;
                  case 1:
                    cout << "single " << score << endl;
                    break;
                  case 2:
                    cout << "double " << score << endl;
                    break;
                  case 3:
                    cout << "triple " << score << endl;
                    break;
                  default:
                    cout << "error";
                  }
                }
                return 0;
              }
            }
          }
        }
      }
    }
  }

  cout << "impossible" << endl;

  return 0;
}
