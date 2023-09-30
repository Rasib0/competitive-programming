#include <iostream>
#include <vector>

using namespace std;

bool isPaired(vector<int> &arr, int max_weight) {
  // for odd numbers prev is -1 (can't be paired)
  // for even numbers prev is a value so we need to match it with a
  int prev = -1;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] <= max_weight) {
      continue;
    }

    if (prev == -1) {
      prev = arr[i];
    } else {
      if (prev != arr[i]) {
        return false;
      }
      prev = -1;
    }
  }

  return prev == -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  int lo = 0;

  // why 1000000001?
  // if we did 1000000000 then lo would never be able to reach 1000000000 so
  // need to do
  // + 1 so that lo reaches 1000000001 too
  int hi = 1000000001;

  // we need the to single out smallest weight where both are paired
  int mid = 0;

  while (lo + 1 < hi) {
    mid = lo + (hi - lo) / 2; // (99 + 100)/ 2 = 99
    bool works = isPaired(a, mid) and isPaired(b, mid);
    if (works) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  if (isPaired(a, lo) and isPaired(b, lo)) {
    cout << lo << endl;
  } else {
    cout << mid << endl;
  }

  return 0;
}
