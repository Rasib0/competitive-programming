#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n; // stores

  while (cin >> n) {

    if (n == 0) {
      break;
    }

    vector<pair<int, double>> stores(n);

    for (int i = 0; i < n; i++) {
      int k; // minutes after openning
      cin >> k;

      double p; // price of spatula
      cin >> p;

      stores[i] = {k, p};
    }

    double max_sum_from_i = 0;

    int start_at = 0;

    int best_start_at = 0;
    int best_end_after = 0;
    double best_sum = 0;

    for (int end = 0; end < n; end++) {

      double profit_at_i = stores[end].second - 0.08;
      double cost_inbetween{};

      if (end == start_at) {
        cost_inbetween = 0;
      } else {
        cost_inbetween = 0.08 * (stores[end].first - stores[end - 1].first - 1);
      }

      if (max_sum_from_i - cost_inbetween + profit_at_i <= profit_at_i) {
        max_sum_from_i = profit_at_i;
        start_at = end;
      } else {
        max_sum_from_i = max_sum_from_i - cost_inbetween + profit_at_i;
      }

      if (max_sum_from_i > best_sum) {
        best_start_at = start_at;
        best_end_after = end;
        best_sum = max_sum_from_i;
      }
    }

    if (best_sum == 0) {
      cout << "no profit" << endl;
    } else {
      cout << fixed << setprecision(2) << best_sum << " "
           << stores[best_start_at].first << " " << stores[best_end_after].first
           << endl;
    }
  }

  return 0;
}
