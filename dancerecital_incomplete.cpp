#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getQuickChangeCount(vector<string> list) {
  int count = 0;

  for (int i = 0; i < list.size() - 1; i++) {
    string order2 = list[i];
    string order1 = list[i + 1];

    // find the number of same characters between string a and b
    for (auto &o1 : order1) {
      for (auto &o2 : order2) {
        if (o1 == o2) {
          count++;
          break;
        }
      }
    }
  }

  return count;
}

int main() {
  int n;
  cin >> n;
  vector<string> list;

  for (int i = 0; i < n; i++) {
    string recital;
    cin >> recital;

    list.push_back(recital);
  }
  int min = getQuickChangeCount(list);

  sort(list.begin(), list.end());

  while (next_permutation(list.begin(), list.end())) {
    if (min > getQuickChangeCount(list)) {
      min = getQuickChangeCount(list);
    }
  }

  cout << min << endl;
  return 0;
}
