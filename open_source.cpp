#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  unordered_map<string, int> project_count;
  unordered_map<string, vector<string>> students_projs;

  vector<string> input;
  string line;
  string proj;

  while (getline(cin, line)) {
    input.push_back(line);
  }

  // remove all elements that appear twice or more
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == "0") {
      break;
    }

    if (input[i] == "1") {
      for (auto &[_, st_set] : students_projs) {
        if (st_set.size() > 1) {
          for (auto &v : st_set) {
            project_count[v]--;
          }
        }
      }

      vector<pair<string, int>> sorted_results(project_count.begin(),
                                               project_count.end());

      sort(sorted_results.begin(), sorted_results.end(),
           [](auto &left, auto &right) {
             if (left.second == right.second) {
               return left.first < right.first;
             }
             return left.second > right.second;
           });

      for (const auto &i : sorted_results) {
        cout << i.first << " " << i.second << endl;
      }

      project_count.clear();
      students_projs.clear();

      continue;
    }

    if ((input[i][0] >= 'A') && (input[i][0] <= 'Z')) {
      proj = input[i];
      project_count[proj] = 0;
      continue;
    }

    string student = input[i];

    // don't update project count for repetation
    if (find(students_projs[student].begin(), students_projs[student].end(),
             proj) == students_projs[student].end()) {
      students_projs[student].push_back(proj);
      project_count[proj]++;
    }
  }

  return 0;
}
