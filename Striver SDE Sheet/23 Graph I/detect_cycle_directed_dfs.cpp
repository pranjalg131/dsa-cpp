#include <bits/stdc++.h>
using namespace std;

class Solution {

  bool dfs(int s, vector<vector<int>> &adj, vector<bool> &visited,
           vector<bool> &currCycleVisited) {
    visited[s] = true;
    currCycleVisited[s] = true;

    for (auto n : adj[s]) {
      if (currCycleVisited[n]) {
        return true;
      } else {
        if (dfs(n, adj, visited, currCycleVisited))
          return true;
      }
    }

    currCycleVisited[s] = false;
    return false;
  }

  int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    vector<vector<int>> adj(n + 1);

    for (auto e : edges) {
      adj[e.first].push_back(e.second);
    }

    vector<bool> visited(n + 1, false);
    vector<bool> currCycleVisited(n + 1, false);

    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        if (dfs(i, adj, visited, currCycleVisited))
          return 1;
      }
    }

    return 0;
  }
};