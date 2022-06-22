#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
  vector<int> rank;
  vector<int> parent;

public:
  DSU(int n) {
    rank = vector<int>(n, 0);
    parent.resize(n);
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int findParent(int node) {

    if (node == parent[node])
      return node;

    return parent[node] = findParent(parent[node]);
  }

  void Union(int u, int v) {
    u = findParent(u);
    v = findParent(v);

    if (rank[u] > rank[v]) {
      parent[v] = u;
    } else if (rank[v] > rank[u]) {
      parent[u] = v;
    } else {
      parent[v] = u;
      rank[u]++;
    }
  }
};