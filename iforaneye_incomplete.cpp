#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    map<string, string> substitude;

    substitude["four"] = "4";
    substitude["and"] = "&";
    substitude["won"] = "1";
    substitude["one"] = "1";
    substitude["two"] = "2";
    substitude["too"] = "2";
    substitude["bea"] = "b";
    substitude["for"] = "4";
    substitude["bee"] = "b";
    substitude["see"] = "c";
    substitude["sea"] = "c";
    substitude["eye"] = "i";
    substitude["why"] = "y";
    substitude["owe"] = "o";
    substitude["are"] = "r";
    substitude["you"] = "u";
    substitude["at"] = "@";
    substitude["to"] = "2";
    substitude["be"] = "b";
    substitude["oh"] = "o";

    substitude["Four"] = "4";
    substitude["And"] = "&";
    substitude["Won"] = "1";
    substitude["One"] = "1";
    substitude["Two"] = "2";
    substitude["Too"] = "2";
    substitude["Bea"] = "B";
    substitude["For"] = "4";
    substitude["Bee"] = "B";
    substitude["See"] = "C";
    substitude["Sea"] = "C";
    substitude["Eye"] = "I";
    substitude["Why"] = "Y";
    substitude["Owe"] = "O";
    substitude["Are"] = "R";
    substitude["You"] = "U";
    substitude["At"] = "@";
    substitude["To"] = "2";
    substitude["Be"] = "B";
    substitude["Oh"] = "O";

    for (int i = 0; i < n; i++)
    {
        string result;
        getline(cin, result);

        for (const auto &[search, replace] : substitude)
        {

            size_t pos = result.find(search);

            if (pos == string::npos)
            {
                string searchc = search;
                searchc[0] = toupper(search[0]);

                pos = result.find(searchc);
            }

            while (pos != string::npos)
            {
                result.replace(pos, search.length(), replace);
                pos = result.find(search, pos + replace.length());

                if (pos == string::npos)
                {
                    string searchc = search;
                    searchc[0] = toupper(search[0]);

                    pos = result.find(searchc, pos + replace.length());
                }
            }
        }
        cout << result << endl;
    }

    return 0;
}