#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool bfs(int v, int parent, vector<vector<int>> &adj, vector<bool> visited) {

    queue<pair<int, int>> Q;
    visited[v] = true;
    Q.push({v, parent});

    while (!Q.empty()) {
      int curr = Q.front().first;
      int curr_parent = Q.front().second;
      Q.pop();

      for (auto n : adj[curr]) {
        if (n == curr_parent)
          continue;
        if (!visited[n]) {
          visited[n] = true;
          Q.push({n, curr});
        } else {
          return true;
        }
      }
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
        if (bfs(i, -1, adj, visited))
          return "Yes";
      }
    }
    return "No";
  }
};