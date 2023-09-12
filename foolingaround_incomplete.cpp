#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int testcases;
  cin >> testcases; // 1 to 100

  vector<int> primes;

  // sieve of eratosthenes

  map<int, bool> winner;
  winner[1] = true;

  for (int i = 0; i < testcases; i++) {
    int N;
    cin >> N; // 1 <= N <= 10^9
              //
  }

  return 0;
}

vector<int> sieveOfEratosthenes(int n) {
  vector<int> primes;
  vector<bool> isComposite(n + 1, false);
}
