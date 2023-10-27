#include <iostream>
#include <unordered_map>
#define int long long
#define endl "\n"
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define MOD 1000000007

using namespace std;

int subroutine(string &word, unordered_map<string, int> &m,
               unordered_map<string, int> &memo) {
  if (memo.find(word) != memo.end())
    return memo[word];
  if (word.size() == 0)
    return 1;

  int s = 0;
  for (int i = 0; i <= word.size(); i++) {
    string first_part = word.substr(0, i);
    string second_part = word.substr(i);

    if (m.find(first_part) != m.end()) {
      s += m[first_part] * subroutine(second_part, m, memo);
    }
  }

  memo[word] = s % MOD;
  return memo[word];
}

int32_t main() {
  IOS;
  int N;
  string word;
  cin >> N >> word;

  unordered_map<string, int> m;

  for (int i = 0; i < N; i++) {
    string k;
    int e;
    cin >> k >> e;
    m[k] = e;
  }

  unordered_map<string, int> memo;

  cout << subroutine(word, m, memo) << endl;
  return 0;
}
