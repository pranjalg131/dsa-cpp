#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool dfs(int v, int parent, vector<vector<int>> &adj, vector<bool> visited) {
    visited[v] = true;

    for (auto n : adj[v]) {
      if (!visited[n]) {
        if (dfs(n, v, adj, visited))
          return true;
      } else if (n == parent)
        continue;
      else
        return true;
    }

    return false;
  }

  string cycleDetection(vector<vector<int>> &edges, int n, int m) {
    vector<vector<int>> adj(n + 1);

    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        if (dfs(i, -1, adj, visited))
          return "Yes";
      }
    }
    return "No";
  }
};