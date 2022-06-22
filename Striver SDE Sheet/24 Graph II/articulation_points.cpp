#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  void dfs(int s, int parent, int &timer, vector<bool> &visited,
           vector<int> &tIn, vector<int> &tMin, vector<vector<int>> &adj,
           unordered_set<int> &S) {

    visited[s] = true;
    tIn[s] = tMin[s] = timer++;

    int child = 0;

    for (auto n : adj[s]) {
      if (n == parent)
        continue;

      if (!visited[n]) {
        child++;
        dfs(n, s, timer, visited, tIn, tMin, adj, S);
        tMin[s] = min(tMin[s], tMin[n]);
        if (tMin[n] >= tIn[s] && parent != -1) {
          S.insert(n);
        }
      } else {
        tMin[s] = min(tMin[s], tIn[n]);
      }
    }

    if (child > 0 && parent == -1)
      S.insert(s);
  }

  vector<int> findArticulationPoints(int n, vector<vector<int>> &connections) {

    vector<vector<int>> adj(n);

    for (auto c : connections) {
      adj[c[0]].push_back(c[1]);
      adj[c[1]].push_back(c[0]);
    }

    vector<bool> visited(n, false);
    vector<int> tIn(n, -1), tMin(n, -1);
    int timer = 0;
    unordered_set<int> S;

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i, -1, timer, visited, tIn, tMin, adj, S);
      }
    }

    vector<int> ans(S.begin(), S.end());
    return ans;
  }
};