#include <iostream>
#include <map>
#include <sstream>
#include <vector>

// unique positive integers called marks
// used to measure distances by using the difference between pairs of marks
// {0, 1, 3} is golomb ruler which

using namespace std;
// let's use two for loop that don't repeat, then we can check if the distance
// repeat if they do then it's not golmb ruler
int main() {

  string line;

  while (getline(cin, line)) {
    // distances -> count
    map<int, int> distances;
    istringstream iss(line);
    vector<int> marks;

    while (iss >> line) {
      int mark = stoi(line);
      marks.push_back(mark);
    }

    for (int i = 0; i < marks.size(); i++) {
      for (int j = i + 1; j < marks.size(); j++) {
        int distance = abs(marks[i] - marks[j]);

        if (distances.count(distance) > 0) {
          distances[distance] += 1;
        } else {
          distances[distance] = 1;
        }
      }
    }

    int largest_mark = distances.rbegin()->first;
    bool not_a_ruler = false;

    vector<int> missing;

    for (int i = 1; i < largest_mark; i++) {
      if (distances.count(i) == 0) {
        missing.push_back(i);
      } else if (distances[i] > 1) {
        cout << "not a ruler" << endl;
        not_a_ruler = true;
        break;
      }
    }

    if (not_a_ruler) {
      continue;
    }

    if (distances.size() == largest_mark) {
      cout << "perfect" << endl;
      continue;
    }

    cout << "missing";
    for (auto &m : missing) {
      cout << " " << m;
    }
    cout << endl;
  }

  return 0;
}
