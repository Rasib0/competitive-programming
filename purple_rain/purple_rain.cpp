#include <iostream>
#include <vector>
#define int long long int

using namespace std;

int32_t main() {
  string s;
  cin >> s;

  int n = s.size();

  pair<size_t, size_t> best_pair;
  pair<size_t, size_t> best_pair2;

  int max_a = 0;
  int max_b = 0;
  int start_a = 0;
  int start_b = 0;
  int sum_a = 0;
  int sum_b = 0;

  for (int end = 0; end < n; end++) {
    int curr_b = (s[end] == 'B') ? 1 : -1;
    int curr_a = (s[end] == 'B') ? -1 : 1;

    if (curr_b > sum_b + curr_b) {
      sum_b = curr_b;
      start_b = end;
    } else {
      sum_b += curr_b;
    }

    if (curr_a > sum_a + curr_a) {
      sum_a = curr_a;
      start_a = end;
    } else {
      sum_a += curr_a;
    }

    if (sum_b > max_b) {
      max_b = sum_b;
      best_pair2.first = start_b + 1;
      best_pair2.second = end + 1;
    }

    if (sum_a > max_a) {
      max_a = sum_a;
      best_pair.first = start_a + 1;
      best_pair.second = end + 1;
    }
  }

  if (max_a == max_b) {
    if (best_pair.first < best_pair2.first) {
      cout << best_pair.first << " " << best_pair.second << endl;
    } else if (best_pair.first > best_pair2.first) {
      cout << best_pair2.first << " " << best_pair2.second << endl;
    } else {
      if (best_pair.second < best_pair2.second) {
        cout << best_pair.first << " " << best_pair.second << endl;
      } else {
        cout << best_pair2.first << " " << best_pair2.second << endl;
      }
    }
  }

  else if (max_a > max_b) {
    cout << best_pair.first << " " << best_pair.second << endl;
  } else {
    cout << best_pair2.first << " " << best_pair2.second << endl;
  }

  return 0;
}
