#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();

  map<int, map<string, string>> dict;
  dict[4]["four"] = "4";
  dict[4]["Four"] = "4";

  dict[3]["and"] = "&";
  dict[3]["won"] = "1";
  dict[3]["one"] = "1";
  dict[3]["two"] = "2";
  dict[3]["too"] = "2";
  dict[3]["bea"] = "b";
  dict[3]["for"] = "4";
  dict[3]["bee"] = "b";
  dict[3]["see"] = "c";
  dict[3]["sea"] = "c";
  dict[3]["eye"] = "i";
  dict[3]["why"] = "y";
  dict[3]["owe"] = "o";
  dict[3]["are"] = "r";
  dict[3]["you"] = "u";

  dict[3]["And"] = "&";
  dict[3]["Won"] = "1";
  dict[3]["One"] = "1";
  dict[3]["Two"] = "2";
  dict[3]["Too"] = "2";
  dict[3]["Bea"] = "B";
  dict[3]["For"] = "4";
  dict[3]["Bee"] = "B";
  dict[3]["See"] = "C";
  dict[3]["Sea"] = "C";
  dict[3]["Eye"] = "I";
  dict[3]["Why"] = "Y";
  dict[3]["Owe"] = "O";
  dict[3]["Are"] = "R";
  dict[3]["You"] = "U";

  dict[2]["at"] = "@";
  dict[2]["to"] = "2";
  dict[2]["be"] = "b";
  dict[2]["oh"] = "o";

  dict[2]["At"] = "@";
  dict[2]["To"] = "2";
  dict[2]["Be"] = "B";
  dict[2]["Oh"] = "O";

  for (int i = 0; i < n; i++) {
    string input;
    getline(cin, input);
    stringstream iss(input);

    string result = "";

    string word;
    while (iss >> word) {

      for (int i = 0; i < word.size(); i++) {

        bool replaced = false;

        for (int len = 4; len >= 2; len--) {
          if (i < word.size() - len + 1 and not replaced) {
            string substring = word.substr(i, len);

            for (auto &[key, entry] : dict[len]) {
              if (substring == key) {
                word.replace(i, len, entry);
                i = i + entry.size() - 1;
                replaced = true;
                break;
              }
            }
          }
        }
      }
      result = result + word + " ";
    }
    cout << result << endl;
  }

  return 0;
}
