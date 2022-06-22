#include <bits/stdc++.h>
using namespace std;

class Solution {

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

public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[]) {

    vector<pair<int, pair<int, int>>> edges;

    for (int u = 0; u < V; u++) {
      for (auto n : adj[u]) {
        int v = n[0];
        int w = n[1];

        edges.push_back({w, {u, v}});
      }
    }

    sort(edges.begin(), edges.end());

    int ans = 0;
    DSU dsu(V);

    for (auto e : edges) {
      int weight = e.first;
      int u = e.second.first;
      int v = e.second.second;

      if (dsu.findParent(u) != dsu.findParent(v)) {
        ans += weight;
        dsu.Union(u, v);
      }
    }

    return ans;
  }
};