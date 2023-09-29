#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n;
  cin >> n;

  vector<long long> v(n);

  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }

  long long total_weight = 0;

  for (long long i = 0; i < (1 << n); i++) {
    long long basket_sum = 0;
    for (long long j = 0; j < n; j++) {
      if ((i & (1ll << j))) {
        basket_sum += v[j];
      }
    }

    if (basket_sum >= 200) {
      total_weight += basket_sum;
    }
  }

  cout << total_weight << endl;
  return 0;
}
