// marked
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

using namespace std;

int knapsack2(vector<int> &w, vector<int> &p, unordered_map<int, int> &memo,
              unordered_map<int, int> &prev, int size, int sum) {
  if (size < 0)
    return 0;
  if (size == 0)
    return sum;

  int maximum = 0;
  for (int i = 0; i < w.size(); i++) {
    int profit = knapsack2(w, p, memo, prev, size - w[i], sum + p[i]);

    if (profit >= maximum) {
      maximum = profit;
      prev[size] = i;
    }
  }
  return maximum;
}

int knapsack(vector<int> &w, vector<int> &p, unordered_map<int, int> &memo,
             unordered_map<int, int> &prev, int size, int idx) {
  if (size < 0)
    return 0;
  if (size == 0)
    return p[idx];

  int maximum = 0;
  int sum = 0;
  for (int i = 0; i < w.size(); i++) {
    sum += knapsack(w, p, memo, prev, size - w[i], i);

    if (sum >= maximum) {
      maximum = sum;
      prev[size] = i;
    }
  }
  return maximum;
}

int main() {
  vector<int> w = {2, 4, 3, 4};
  vector<int> p = {1, 3, 2, 2};

  unordered_map<int, int> prev{};
  unordered_map<int, int> memo{};

  int size = 10;
  int profit = knapsack(w, p, memo, prev, size, 0);

  cout << "Profit for size " << size << ": " << profit << endl;

  while (size > 0) {
    cout << w[prev[size]] << " ";
    size -= w[prev[size]];
  }

  cout << endl;

  return 0;
}
