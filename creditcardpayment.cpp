#include <cmath>
#include <iostream>
#define eps 1e-9
using namespace std;

int main() {
  int test_cases;
  cin >> test_cases;

  for (int t = 0; t < test_cases; t++) {
    double R, B, M;
    // R is the interest rate, so balance += outstading balance*R
    cin >> R >> B >> M;

    double balance = B;
    double rate = R;
    double monthly_payment = M;
    int number_of_payments;

    for (number_of_payments = 0; number_of_payments < 1200;
         number_of_payments++) {
      double interest = round(balance * rate) / 100;
      balance += interest;
      balance = round(balance * 100) / 100;
      // cout << "Interest: " << interest << " |";
      // cout << " New balance: " << balance << " |";
      balance -= monthly_payment;
      // cout << " Balance after payment: " << balance << endl;

      if (balance < eps) {
        cout << number_of_payments + 1 << endl;
        break;
      }
    }

    if (number_of_payments >= 1200) {
      cout << "impossible" << endl;
    }
  }

  return 0;
}
