#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string input;
  cin >> input;
  vector<string> list;

  for (int i = 0 + 1; i < input.size(); i++)
  {
    for (int j = (i + 1) + 1; j < input.size(); j++)
    {

      string first_word = input.substr(0, i);
      string second_word = input.substr(i, j - i);
      string third_word = input.substr(j);

      reverse(first_word.begin(), first_word.end());
      reverse(second_word.begin(), second_word.end());
      reverse(third_word.begin(), third_word.end());

      list.push_back(first_word + second_word + third_word);
    }
  }

  sort(list.begin(), list.end());
  cout << list[0] << endl;

  return 0;
}
