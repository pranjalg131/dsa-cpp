#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> MSTSet(V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});

    while (!pq.empty()) {

      int currNode = pq.top().second;
      pq.pop();

      MSTSet[currNode] = true;

      for (auto n : adj[currNode]) {
        int u = n[0];
        int weight = n[1];

        if (!MSTSet[u] && weight < key[u]) {
          parent[u] = currNode;
          key[u] = weight;
          pq.push({weight, u});
        }
      }
    }

    int ans = 0;
    for (auto w : key)
      ans += w;

    return ans;
  }
};