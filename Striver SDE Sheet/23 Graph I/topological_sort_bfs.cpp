#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Function to return list containing vertices in Topological order.

  vector<int> bfs(int i, int V, vector<int> adj[], vector<int> &indegree) {

    vector<int> ans;
    queue<int> Q;

    for (int i = 0; i < V; i++)
      if (indegree[i] == 0)
        Q.push(i);

    while (!Q.empty()) {

      int curr = Q.front();
      ans.push_back(curr);
      Q.pop();

      for (auto n : adj[curr]) {
        indegree[n]--;
        if (indegree[n] == 0)
          Q.push(n);
      }
    }

    return ans;
  }

  vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
      for (auto x : adj[i])
        indegree[x]++;
    }

    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) {
        return bfs(i, V, adj, indegree);
      }
    }
    return {};
  }
};