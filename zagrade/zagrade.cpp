#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;

  vector<pair<int, int>> bracket_pairs;
  set<string> list;

  stack<int> open_brackets;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      open_brackets.push(i);

    } else if (s[i] == ')') {
      int open_index = open_brackets.top();
      open_brackets.pop();
      bracket_pairs.push_back(make_pair(open_index, i));
    }
  }

  // for each subset of brackets store the string in ans
  for (int i = 1; i < (1 << bracket_pairs.size()); i++) {
    string temp = s;
    for (int j = 0; j < bracket_pairs.size(); j++) {
      // if the jth bit is set, remove the jth bracket pair
      if (i & (1 << j)) {
        temp[bracket_pairs[j].first] = '$';
        temp[bracket_pairs[j].second] = '$';
      }
    }

    // remove all spaces
    temp.erase(remove(temp.begin(), temp.end(), '$'), temp.end());
    list.insert(temp);
  }

  for (auto &element : list) {
    cout << element << endl;
  }
}
