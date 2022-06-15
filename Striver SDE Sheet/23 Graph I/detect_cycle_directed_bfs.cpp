#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (auto e : edges) {
      indegree[e.second]++;
      adj[e.first].push_back(e.second);
    }

    queue<int> Q;
    for (int i = 1; i <= n; i++) {
      if (indegree[i] == 0)
        Q.push(i);
    }

    vector<int> topoSort;

    while (!Q.empty()) {
      int curr = Q.front();
      topoSort.push_back(curr);
      Q.pop();

      for (auto n : adj[curr]) {
        indegree[n]--;
        if (indegree[n] == 0)
          Q.push(n);
      }
    }

    return topoSort.size() != n;
  }
};