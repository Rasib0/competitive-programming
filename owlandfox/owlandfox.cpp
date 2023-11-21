#include <iostream>

using namespace std;

int main() {
  int test_cases;
  cin >> test_cases;

  for (int t = 0; t < test_cases; t++) {
    int N;
    cin >> N;

    int N_sum = 0;
    int N_temp = N;

    while (N_temp) {
      N_sum += N_temp % 10;
      N_temp /= 10;
    }

    for (int i = N - 1; i >= 0; i--) {
      int sum = 0;
      int i_temp = i;

      while (i_temp) {
        sum += i_temp % 10;
        i_temp /= 10;
      }

      if (N_sum == sum + 1) {
        cout << i << endl;
        break;
      }
    }
  }

  return 0;
}
