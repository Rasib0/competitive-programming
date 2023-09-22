#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;

  vector<pair<int, int>> bracket_pairs;
  vector<string> ans;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      // save the index of the open bracket
      // and -1 for the close bracket
      bracket_pairs.push_back(make_pair(i, -1));
    } else if (s[i] == ')') {
      // find the last open bracket
      // and set the close bracket index
      for (int j = bracket_pairs.size() - 1; j >= 0; j--) {
        if (bracket_pairs[j].second == -1) {
          bracket_pairs[j].second = i;
          break;
        }
      }
    }
  }

  // for each subset of brackets store the string in ans
  for (int i = 1; i < (1 << bracket_pairs.size()); i++) {
    string temp = s;
    for (int j = 0; j < bracket_pairs.size(); j++) {
      // if the jth bit is set, remove the jth bracket pair
      if ((i & (1 << j)) >> j) {
        temp[bracket_pairs[j].first] = ' ';
        temp[bracket_pairs[j].second] = ' ';
      }
    }

    // remove all spaces
    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
    ans.push_back(temp);
  }

  sort(ans.begin(), ans.end());
  for (auto it = ans.begin(); it != ans.end(); it++) {
    cout << *it << endl;
  }
}
