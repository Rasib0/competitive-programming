#include <iostream>
#include <set>
#include <unordered_set>
#include <utility>

using namespace std;

struct PairHash {
  template <typename T1, typename T2>
  auto operator()(const pair<T1, T2> &p) const -> size_t {
    return (hash<T1>{}(p.first) << 32) | hash<T2>{}(p.second);
  }
};

int main() {
  // N ingredient,
  int N, M;
  cin >> N >> M;

  unordered_set<pair<int, int>, PairHash> pairs;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    pairs.insert({a, b});
  }

  int count = 1 << N;

  // run from 1 to 2^(N-1)
  for (int i = 0; i < (1 << N); i++) {
    for (auto &[a, b] : pairs) {

      int r = (1 << (a - 1)) | (1 << (b - 1));

      // if a, b are in the subset, (b & r) = r
      if ((i & r) == r) {
        count--;
        break;
      }
    }
  }

  cout << count << endl;

  return 0;
}
