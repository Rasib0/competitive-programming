#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#define MAX_INT 2147483647

using namespace std;

// this is O(n log m)
int getQuickChangeCount2(string &order1, string &order2) {
  int count = 0;

  for (auto &char1 : order1) {
    if (binary_search(order2.begin(), order2.end(), char1)) {
      count++;
    }
  }
  return count;
}

// this is faster than getQuickChangeCount 0.03s seconds faster O(n)
int getQuickChangeCount(string &order1, string &order2) {
  int count = 0;
  vector<int> order1_bits(26);
  vector<int> order2_bits(26);

  for (auto &char1 : order1) {
    order1_bits[char1 - 'A'] = 1;
  }

  for (auto &char2 : order2) {
    order2_bits[char2 - 'A'] = 1;
  }

  for (int i = 0; i < 26; i++) {
    if (order1_bits[i] && order2_bits[i]) {
      count++;
    }
  }
  return count;
}

struct PairHash {
  template <typename T1, typename T2>
  auto operator()(const pair<T1, T2> &p) const -> size_t {
    return (hash<T1>{}(p.first) << 32) | hash<T2>{}(p.second);
  }
};

int main() {
  int n;
  cin >> n;
  vector<string> recitals(n);
  vector<int> perms(n);

  // the trick is ermutate an int array of size n and don't permutate the
  // initial array
  // - we can do this becasue the string has no repeated characters
  // Then you can use the input string array index as key to store the
  // quick change count in a hash map (dynamic programming)
  for (int i = 0; i < n; i++) {
    perms[i] = i;
  }

  unordered_map<pair<int, int>, int, PairHash> quickChangeCount;

  for (int i = 0; i < n; i++) {
    string recital;
    cin >> recital;

    recitals[i] = recital;
  }

  sort(perms.begin(), perms.end());
  int min = MAX_INT;

  while (next_permutation(perms.begin(), perms.end())) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {

      auto ith_pair = make_pair(perms[i], perms[i + 1]);

      auto iter = quickChangeCount.find(ith_pair);

      if (iter == quickChangeCount.end()) {
        quickChangeCount[ith_pair] =
            getQuickChangeCount(recitals[perms[i]], recitals[perms[i + 1]]);
        quickChangeCount[make_pair(perms[i + 1], perms[i])] =
            quickChangeCount[ith_pair];
      }

      count += quickChangeCount[ith_pair];
    }

    if (min > count) {
      min = count;
    }
  }

  cout << min << endl;
  return 0;
}
