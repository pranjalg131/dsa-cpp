#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void dfs(int s, int parent, int &timer, vector<bool> &visited,
           vector<int> &tIn, vector<int> &tMin, vector<vector<int>> &adj,
           vector<vector<int>> &ans) {
    visited[s] = true;
    tIn[s] = tMin[s] = timer++;

    for (auto n : adj[s]) {
      if (n == parent)
        continue;

      if (!visited[n]) {
        dfs(n, s, timer, visited, tIn, tMin, adj, ans);
        tMin[s] = min(tMin[s], tMin[n]);
        if (tMin[n] > tIn[s]) {
          ans.push_back({s, n});
        }
      } else {
        tMin[s] = min(tMin[s], tIn[n]);
      }
    }
  }

  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    vector<vector<int>> adj(n);

    for (auto c : connections) {
      adj[c[0]].push_back(c[1]);
      adj[c[1]].push_back(c[0]);
    }

    vector<bool> visited(n, false);
    vector<int> tIn(n, -1), tMin(n, -1);
    vector<vector<int>> ans;

    int timer = 0;

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i, -1, timer, visited, tIn, tMin, adj, ans);
      }
    }

    return ans;
  }
};