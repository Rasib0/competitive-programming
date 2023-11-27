#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> permutations;
  vector<int> permutation;
  for (int i = 1; i <= n; i++) {
    permutation.push_back(i);
  }

  do {
    permutations.push_back(permutation);
  } while (next_permutation(permutation.begin(), permutation.end()));

  for (auto permutation : permutations) {
    for (auto element : permutation) {
      cout << element << " ";
    }
    cout << endl;
  }

  return 0;
}
