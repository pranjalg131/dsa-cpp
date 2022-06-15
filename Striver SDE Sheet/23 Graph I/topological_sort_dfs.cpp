#include <bits/stdc++.h>
using namespace std;

class Soluion {
public:
  void dfs(int s, vector<vector<int>> &adj, vector<bool> &visited,
           vector<int> &ans) {
    visited[s] = true;

    for (auto n : adj[s]) {
      if (!visited[n])
        dfs(n, adj, visited, ans);
    }

    ans.push_back(s);
  }

  vector<int> topologicalSort(vector<vector<int>> &edges, int n, int m) {
    vector<vector<int>> adj(n);

    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
    }

    vector<bool> visited(n, false);
    vector<int> ans;

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i, adj, visited, ans);
      }
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};