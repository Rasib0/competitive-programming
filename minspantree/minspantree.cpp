#include <algorithm>
#include <iostream>
#include <type_traits>
#include <unordered_map>
#include <vector>
#define int long long int

using namespace ::std;

struct PairHash {
  template <typename T1, typename T2>
  auto operator()(const pair<T1, T2> &p) const -> size_t {
    return (hash<T1>{}(p.first) << 32) | hash<T2>{}(p.second);
  }
};

// sets the parents to themselves and rank to 0
void init(vector<int> &parent, vector<int> &rank, int n) {
  for (int i = 0; i < n; i++)
    parent[i] = i, rank[i] = 0;
}

// find the parent of a node
int find_set(int v, vector<int> &parent) {
  if (v == parent[v])
    return v;

  // path compression missing 🤠
  return parent[v] = find_set(parent[v], parent);
}

// union of two sets
void union_sets(int a, int b, vector<int> &parent, vector<int> &rank) {
  int pa = find_set(a, parent);
  int pb = find_set(b, parent);
  if (pa != pb) {
    if (rank[pa] < rank[pb])
      swap(pa, pb);
    parent[pb] = pa; // b is smaller
    if (rank[pa] == rank[pb])
      rank[pa]++;
  }
}

int32_t main() {
  int n, m;
  // n: numbers of nodes
  // m: numbers of edges
  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;
    // nodes are numbered from 0 to n - 1
    // m lines below: u v w (edge between u and v with weight w)
    // Find MST (minimum spanning tree) using kruskal algorithm
    int u, v, w;

    vector<pair<pair<int, int>, int>> sortedEdges;
    for (int i = 0; i < m; i++) {
      cin >> u >> v >> w;
      sortedEdges.push_back({{u, v}, w});
    }

    sort(sortedEdges.begin(), sortedEdges.end(),
         [](const auto &a, const auto &b) { return a.second < b.second; });

    vector<int> parent(n), rank(n);
    int cost = 0;
    vector<pair<int, int>> result;
    init(parent, rank, n);

    for (auto &[edge, weight] : sortedEdges) {
      int u = edge.first;
      int v = edge.second;

      if (find_set(u, parent) != find_set(v, parent)) {
        union_sets(u, v, parent, rank);
        cost += weight;
        if (u > v)
          swap(u, v); // x=u < y=v
        result.push_back({u, v});
      }
    }

    // if the graph is not connected (i.e. not a tree with n nodes)
    if (result.size() != n - 1) {
      cout << "Impossible" << endl;
      continue;
    }

    cout << cost << endl;
    sort(result.begin(), result.end());

    for (auto &[u, v] : result) {
      cout << u << " " << v << endl;
    }
  }
  return 0;
}

// Note: A lot of boilerplate but the code itself is simple
// Union Find
