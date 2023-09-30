#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  long long total_weight = 0;

  for (int i = 0; i < n; i++) {
    total_weight += v[i];
  }

  // 2^40 so we need long long
  total_weight *= 1ll << (n - 1);
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    sum = v[i];
    total_weight -= sum < 200 ? sum : 0;

    for (int j = i + 1; j < n; j++) {
      sum = v[i] + v[j];
      total_weight -= sum < 200 ? sum : 0;

      for (int k = j + 1; k < n; k++) {
        sum = v[i] + v[j] + v[k];
        total_weight -= sum < 200 ? sum : 0;
      }
    }
  }

  cout << total_weight << endl;
  return 0;
}
