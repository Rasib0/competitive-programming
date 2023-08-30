#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int test_cases;
  cin >> test_cases;

  for (int t = 0; t < test_cases; t++) {
    float R, B, M;
    // R is the interest rate, so balance += outstading balance*R
    cin >> R >> B >> M;

    float outstanding_balance = B;
    float interest_rate = R;
    float max_monthly_payment = M;
    int number_of_payments = 0;

    for (int i = 0; i < 1200; i++) {
      outstanding_balance -= max_monthly_payment;
      outstanding_balance += round(outstanding_balance * interest_rate / 100);

      if (max_monthly_payment >= outstanding_balance) {
        cout << i + 1 << endl;
        break;
      }
    }

    cout << "impossible" << endl;
  }

  return 0;
}
