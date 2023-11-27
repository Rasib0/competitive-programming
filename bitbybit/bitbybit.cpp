#include <iostream>
#include <vector>
// 31 -> high order bit
// 0 -> low-order bit

using namespace std;
int main()
{
  // read the input
  while (true)
  {

    int n; // n <= 100
    cin >> n;

    if (n == 0)
    {
      return 0; // exit
    }

    vector<char> bits(32, '?');

    for (int i = 0; i < n; i++)
    {

      string opt_code{};
      cin >> opt_code;

      if (opt_code == "CLEAR")
      {
        int operand{};
        cin >> operand;
        bits[operand] = '0';
      }
      else if (opt_code == "SET")
      {
        int operand;
        cin >> operand;
        bits[operand] = '1';
      }

      else if (opt_code == "OR")
      {
        int operand1, operand2;
        cin >> operand1 >> operand2;

        if (bits[operand1] == '1' or bits[operand2] == '1')
        {
          bits[operand1] = '1';
        }
        else if (bits[operand1] == '0' and bits[operand2] == '?')
        {
          bits[operand1] = '?';
        }
      }

      else if (opt_code == "AND")
      {
        int operand1, operand2;
        cin >> operand1 >> operand2;

        if (bits[operand1] == '1' and bits[operand2] == '1')
        {
          bits[operand1] = '1';
        }
        else if (bits[operand1] == '0' or bits[operand2] == '0')
        {
          bits[operand1] = '0';
        }
        else if (bits[operand2] == '?')
        {
          bits[operand1] = '?';
        }
      }
    }

    for (auto it = bits.rbegin(); it != bits.rend(); it++)
    {
      cout << *it;
    }
    cout << endl;
  }

  return 0;
}
