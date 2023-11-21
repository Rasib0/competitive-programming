#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, P;
  cin >> N >> P;

  vector<int> v(N);

  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  int sum = 0;
  int best = 0;
  for (int i = 0; i < N; i++) {
    sum = max(v[i] - P, sum + v[i] - P);
    best = max(best, sum);
  }

  cout << best << endl;
  return 0;
}
