#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void helper(int S, vector<int> adj[], vector<bool> &visited,
              vector<int> &ans) {

    queue<int> Q;
    visited[S] = true;
    ans.push_back(S);
    Q.push(S);

    while (!Q.empty()) {
      int curr = Q.front();
      Q.pop();

      for (auto n : adj[curr]) {
        if (!visited[n]) {
          visited[n] = true;
          ans.push_back(n);
          Q.push(n);
        }
      }
    }
  }

  vector<int> bfsOfGraph(int V, vector<int> adj[]) {

    vector<bool> visited(V, false);
    vector<int> ans;

    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        helper(i, adj, visited, ans);
      }
    }

    return ans;
  }
};