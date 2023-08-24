#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << boolalpha;

  string name;
  getline(cin, name);
  cout << "Thank you, " << name << ", and farewell!" << '\n';
  return 0;
}
