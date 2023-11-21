#include <iostream>
#include <map>

using namespace std;

int min_(map<int, int> &map_in) { return map_in.begin()->first; }
int max_(map<int, int> &map_in) { return map_in.rbegin()->first; }

int main() {
  int test_cases;
  cin >> test_cases;

  for (int t = 0; t < test_cases; t++) {
    int n;
    cin >> n;

    map<int, int> ask_prices;
    map<int, int> bid_prices;

    string keyword, trash;
    int price, amount, trade_price{-1};

    for (int i = 0; i < n; i++) {

      cin >> keyword >> amount >> trash >> trash >> price;

      if (keyword == "buy") {
        bid_prices[price] += amount;
      } else {
        ask_prices[price] += amount;
      }

      while (bid_prices.size() and ask_prices.size() and
             max_(bid_prices) >= min_(ask_prices)) {

        trade_price = min_(ask_prices);

        int amount_to_buy =
            min(bid_prices[max_(bid_prices)], ask_prices[min_(ask_prices)]);

        bid_prices[max_(bid_prices)] -= amount_to_buy;
        ask_prices[min_(ask_prices)] -= amount_to_buy;

        if (bid_prices[max_(bid_prices)] == 0) {
          bid_prices.erase(max_(bid_prices));
        }

        if (ask_prices[min_(ask_prices)] == 0) {
          ask_prices.erase(min_(ask_prices));
        }
      }

      // PRINT STEP
      if (ask_prices.size()) {
        cout << min_(ask_prices) << " ";
      } else {
        cout << "-"
             << " ";
      }

      if (bid_prices.size()) {
        cout << max_(bid_prices) << " ";
      } else {
        cout << "-"
             << " ";
      }

      if (trade_price != -1) {
        cout << trade_price << endl;
      } else {
        cout << "-" << endl;
      }
    }
  }
  return 0;
}
