#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Function to return a list containing the DFS traversal of the graph.

  void helper(int V, vector<int> adj[], vector<int> &ans,
              vector<bool> &visited) {
    visited[V] = true;
    ans.push_back(V);

    for (auto n : adj[V]) {
      if (!visited[n]) {
        helper(n, adj, ans, visited);
      }
    }
  }

  vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<int> ans;

    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        helper(i, adj, ans, visited);
      }
    }

    return ans;
  }
};