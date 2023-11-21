#include <iostream>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  // string -> { pos1, pos2 }
  map<string, unordered_set<int>> seenPicturesMap;
  int matchedPicturesCount = 0;

  for (int i = 0; i < K; ++i) {
    int c1, c2;
    string p1, p2;
    cin >> c1 >> c2 >> p1 >> p2;

    seenPicturesMap[p1].insert(c1);
    seenPicturesMap[p2].insert(c2);

    if (p1 == p2) {
      matchedPicturesCount++;
    }
  }

  int seenBothPicturesCount = 0;
  int seenPicturesCount = seenPicturesMap.size();
  int totalPictures = N / 2;

  for (const auto &seenCard : seenPicturesMap) {
    if (seenCard.second.size() == 2) {
      seenBothPicturesCount++;
    }
  }

  // Case 1: if you have seen all pictures (at least once)
  // then we can make all the pair
  // Case 2: if you have seen all cards but a single pair
  // then we can make all the pair
  // Otherwise: We can only match whatever picture we know both positions for.

  if ((seenPicturesCount == totalPictures) ||
      (seenBothPicturesCount == totalPictures - 1)) {
    cout << totalPictures - matchedPicturesCount;
  } else {
    cout << seenBothPicturesCount - matchedPicturesCount;
  }
  return 0;
}
