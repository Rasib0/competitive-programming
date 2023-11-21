#include <iostream>
#include <utility>

using namespace std;

bool nth_bit(int number, int n) { return (number & (1 << n)) >> n; }

struct PairHash {
  template <typename T1, typename T2>
  auto operator()(const pair<T1, T2> &p) const -> size_t {
    return (hash<T1>{}(p.first) << 32) | hash<T2>{}(p.second);
  }
};
