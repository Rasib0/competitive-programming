#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int test_cases;
  cin >> test_cases;

  unordered_map<int, vector<int>> mapping;

  for (int i = 0; i < test_cases; i++) {
    int k;
    cin >> k;
    int n;
    int count = 0;

    while (cin >> n) {
      for (int j = 0; j < n; j++) {
        int id;
        cin >> id;
        mapping[id].push_back(count);
      }
      count++;
    }

    for (auto &[key, value] : mapping) {
      cout << key << ": ";
      for (auto &v : value) {
        cout << v << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
