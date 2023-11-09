#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int subroutine(string keyword, unordered_set<string> &lis,
               unordered_map<string, int> &memo) {
  if (keyword == "") {
    return 1;
  }

  if (memo.find(keyword) != memo.end()) {
    return memo[keyword];
  }

  int count = 0;
  for (auto i = 0; i <= keyword.size(); ++i) {
    string first_part = keyword.substr(0, i);
    string second_part = keyword.substr(i);

    if (lis.find(first_part) != lis.end()) {
      count += subroutine(second_part, lis, memo);
    }
  }

  memo[keyword] = count;
  return memo[keyword];
}

int main() {
  int N;
  cin >> N;
  cin.ignore();

  for (int i = 0; i < N; ++i) {
    string input;
    getline(cin, input);

    unordered_set<string> lis;
    istringstream iss(input);
    string item;
    while (getline(iss, item, ',')) {
      lis.insert(item);
    }

    string keyword;
    cin >> keyword;
    cin.ignore();

    unordered_map<string, int> memo;
    cout << subroutine(keyword, lis, memo) << endl;
  }

  return 0;
}
