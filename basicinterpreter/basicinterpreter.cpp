#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int do_op(string operator_, int value1, int value2) {
  int result;

  if (operator_ == "+") {
    result = value1 + value2;
  } else if (operator_ == "/") {
    result = value1 / value2;
  } else if (operator_ == "-") {
    result = value1 - value2;
  } else if (operator_ == "*") {
    result = value1 * value2;
  } else {
    cout << "Invalid operator: " << operator_ << endl;
  }

  return result;
}

bool do_cond(string conditional, int value1, int value2) {

  if (conditional == "=") {
    return value1 == value2;
  } else if (conditional == "<") {
    return value1 < value2;
  } else if (conditional == ">") {
    return value1 > value2;
  } else if (conditional == "<=") {
    return value1 <= value2;
  } else if (conditional == ">=") {
    return value1 >= value2;
  } else if (conditional == "<>") {
    return value1 != value2;
  } else {
    cout << "Invalid conditional: " << conditional << endl;
    return false;
  }
}

int main() {
  // Read the input values into an array of instructions that is properly sorted
  vector<vector<string>> instructions;
  vector<int> line_numbers;

  map<string, int> variables;

  // init variables from A to Z to 0
  // for (char c = 'A'; c <= 'Z'; c++) {
  //   variables[string(1, c)] = 0;
  // }

  string line;

  while (getline(cin, line)) {
    istringstream iss(line);

    string line_number;
    iss >> line_number;

    string optcode;
    iss >> optcode;

    string rest;
    getline(iss, rest);

    // remove a whitespace;
    rest.erase(0, 1);

    line_numbers.push_back(stoi(line_number));
    instructions.push_back({line_number, optcode, rest});
  }

  sort(instructions.begin(), instructions.end(),
       [](vector<string> a, vector<string> b) {
         return stoi(a[0]) < stoi(b[0]);
       });

  sort(line_numbers.begin(), line_numbers.end());

  // GAME LOOP
  for (int i = 0; i < instructions.size(); i++) {
    vector<string> instruction = instructions[i];

    // cout << instruction[0] << " " << instruction[1] << " " << instruction[2]
    // << endl;

    if (instruction[1] == "PRINT") {

      if (variables.count(instruction[2]) > 0) {
        cout << variables[instruction[2]];

      } else {
        string output_string = instruction[2];
        // remove the "" from beginning and end
        output_string.erase(0, 1);
        output_string.erase(output_string.size() - 1);
        cout << output_string;
      }

    } else if (instruction[1] == "PRINTLN") {

      if (variables.count(instruction[2]) > 0) {
        cout << variables[instruction[2]] << endl;

      } else {
        string output_string = instruction[2];
        // remove the "" from beginning and end
        output_string.erase(0, 1);
        output_string.erase(output_string.size() - 1);

        cout << output_string << endl;
      }

    } else if (instruction[1] == "LET") {
      istringstream iss(instruction[2]);

      string var_name;
      iss >> var_name;

      string equals;
      iss >> equals;

      string value1;
      iss >> value1;

      string operator_;
      iss >> operator_;

      string value2;
      iss >> value2;

      if (value2.size() > 0) {
        if (variables.count(value1) and variables.count(value2)) {
          variables[var_name] =
              do_op(operator_, variables[value1], variables[value2]);

        } else if (variables.count(value1)) {
          variables[var_name] =
              do_op(operator_, variables[value1], stoi(value2));

        } else if (variables.count(value2)) {
          variables[var_name] =
              do_op(operator_, stoi(value1), variables[value2]);

        } else {
          variables[var_name] = do_op(operator_, stoi(value1), stoi(value2));
        }

      } else {

        if (variables.count(value1)) {
          variables[var_name] = variables[value1];
        } else {
          variables[var_name] = stoi(value1);
        }
      }

    } else if (instruction[1] == "IF") {
      istringstream iss(instruction[2]);

      string value1;
      iss >> value1;

      string operator_;
      iss >> operator_;

      string value2;
      iss >> value2;

      string then_trash;
      iss >> then_trash;

      string goto_trash;
      iss >> goto_trash;

      int goto_number;
      iss >> goto_number;

      bool result = false;

      if (variables.count(value1) and variables.count(value2)) {
        result = do_cond(operator_, variables[value1], variables[value2]);

      } else if (variables.count(value1)) {
        result = do_cond(operator_, variables[value1], stoi(value2));

      } else if (variables.count(value2)) {
        result = do_cond(operator_, stoi(value1), variables[value2]);

      } else {
        result = do_cond(operator_, stoi(value1), stoi(value2));
      }

      if (result) {
        i = find(line_numbers.begin(), line_numbers.end(), goto_number) -
            line_numbers.begin() - 1;
      }

    } else {
      cout << "Invalid instruction" << endl;
    }
  }

  return 0;
}
