#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int countUniqueCombinations(int people, vector<vector<int>> &departments,
                            int index, unordered_set<int> &chosenDepartments) {
  if (index == people) {
    return 1;
  }

  int count = 0;
  for (int i = 0; i < departments.size(); ++i) {
    if (chosenDepartments.find(i) == chosenDepartments.end()) {
      for (int j = 0; j < departments[i].size(); ++j) {
        if (departments[i][j] > 0) {
          chosenDepartments.insert(i);
          departments[i][j]--;
          count += countUniqueCombinations(people, departments, index + 1,
                                           chosenDepartments);
          chosenDepartments.erase(i);
          departments[i][j]++;
        }
      }
    }
  }

  return count;
}

int main() {
  int testCases;
  cin >> testCases;

  while (testCases--) {
    int people, departmentsCount;
    cin >> people >> departmentsCount;
    vector<vector<int>> departments(departmentsCount);

    for (int i = 0; i < departmentsCount; ++i) {
      int departmentSize;
      cin >> departmentSize;
      departments[i].resize(departmentSize);
      for (int j = 0; j < departmentSize; ++j) {
        cin >> departments[i][j];
      }
    }

    unordered_set<int> chosenDepartments;
    int uniqueCombinations =
        countUniqueCombinations(people, departments, 0, chosenDepartments);
    cout << uniqueCombinations << endl;
  }
  return 0;
}
