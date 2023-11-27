#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

#define MAX_INT 2147483647

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<bitset<26>> recitals(n);
  vector<int> perms(n);

  for (int i = 0; i < n; i++) {
    perms[i] = i;
  }

  for (int i = 0; i < n; i++) {
    string recital;
    cin >> recital;

    for (auto &char1 : recital) {
      recitals[i][char1 - 'A'] = 1;
    }
  }

  sort(perms.begin(), perms.end());
  int min = MAX_INT;

  while (next_permutation(perms.begin(), perms.end())) {
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
      count += (recitals[perms[i]] & recitals[perms[i + 1]]).count();
    }

    if (min > count) {
      min = count;
    }
  }

  cout << min << endl;
  return 0;
}
