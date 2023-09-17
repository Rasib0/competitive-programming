#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
  int k, n;
  cin >> k >> n;
  // strength of each year after 2011
  map<int, int> strengths;

  // priority queye of size k
  priority_queue<int> pq;

  int karl_year, karl_strength;
  cin >> karl_year >> karl_strength;

  if (karl_year == 2011) {
    pq.push(karl_strength);
  } else {
    strengths[karl_year] = karl_strength;
  }

  // initialing pq with data from year 2011
  // rest of the years goes into the map

  for (int i = 0; i < n + k - 2; i++) {
    int year, strength;
    cin >> year >> strength;

    if (year == 2011) {
      pq.push(strength);
      continue;
    }
    strengths[year] = strength;
  }

  // GAME LOOP
  for (int i = 2011; i <= 2011 + n - 1; i++) {
    int winner = pq.top();

    if (winner == karl_strength) {
      cout << i << endl;
      return 0;
    }

    pq.pop();
    pq.push(strengths[i + 1]);
  }

  cout << "unknown" << endl;
  return 0;
}
