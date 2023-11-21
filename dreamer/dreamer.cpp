#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isLeapYear(int year) {
  if (year % 400 == 0)
    return true;
  if (year % 100 == 0)
    return false;
  if (year % 4 == 0)
    return true;

  return false;
}

bool isValid(int day, int month, int year) {
  bool leapYear = isLeapYear(year);

  // birthday test
  if (year < 2000) {
    return false;
  }

  // months valid test
  if (month < 1 or month > 12) {
    return false;
  }

  // days valid test
  if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or
      month == 10 or month == 12) {
    if (day < 1 or day > 31) {
      return false;
    }
  } else {
    if (month == 2) {
      if (leapYear) {
        if (day < 1 or day > 29) {
          return false;
        }
      } else {
        if (day < 1 or day > 28) {
          return false;
        }
      }
    } else {
      if (day < 1 or day > 30) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int test_cases;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++) {
    string day, month, year;
    cin >> day >> month >> year;

    string curr_string = year + month + day;
    int count = 0;

    string earliest_date = "99999999";

    sort(curr_string.begin(), curr_string.end());

    while (next_permutation(curr_string.begin(), curr_string.end())) {

      if (not isValid(stoi(curr_string.substr(6, 2)),
                      stoi(curr_string.substr(4, 2)),
                      stoi(curr_string.substr(0, 4)))) {
        continue;
      }

      if (curr_string < earliest_date) {
        earliest_date = curr_string;
      }

      count++;
    }

    if (count == 0) {
      cout << count << endl;
      continue;
    }

    cout << count << " " << earliest_date.substr(6, 2) << " "
         << earliest_date.substr(4, 2) << " " << earliest_date.substr(0, 4)
         << endl;
  }

  return 0;
}
