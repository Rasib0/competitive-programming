#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int k = 0; k < t; k++) {
    cin.ignore();
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);

    unordered_map<char, vector<char>> input;

    for (int i = 0; i < line1.size(); i++) {
      if (line1[i] == ' ')
        continue;
      input[line1[i]].push_back(line2[i]);
    }

    // build the vector
    vector<vector<bool>> visited(26, vector<bool>(26));

    for (char letter = 'A'; letter <= 'Z'; letter++) {
      queue<char> q = {};
      q.push(letter);
      visited[letter - 65][letter - 65] = true;

      while (!q.empty()) {
        char top = q.front();
        q.pop();

        for (auto &neighbour : input[top]) {
          if (visited[letter - 65][neighbour - 65]) {

            continue;
          }
          q.push(neighbour);
          visited[letter - 65][neighbour - 65] = true;
        }
      }
    }

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
      string w1, w2;
      cin >> w1 >> w2;
      // cout << i << ": " << w1 << " " << w2 << endl;

      if (w1.size() != w2.size()) {
        cout << "No" << endl;
        continue;
      }

      if (w1.size() < 3 or w2.size() > 20) {
        cout << "No" << endl;
        continue;
      }

      bool valid = true;
      for (int s = 0; s < w2.size(); s++) {

        if (!visited[w1[s] - 65][w2[s] - 65]) {
          valid = false;
          continue;
        }
      }

      if (valid) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }

  return 0;
}
