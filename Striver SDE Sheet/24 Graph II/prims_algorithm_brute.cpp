#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[]) {

    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> MSTSet(V, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {

      int minKey = -1;
      int minDist = INT_MAX;
      for (int i = 0; i < V; i++) {
        if (!MSTSet[i] && key[i] < minDist) {
          minKey = i;
          minDist = key[i];
        }
      }

      MSTSet[minKey] = true;

      for (auto n : adj[minKey]) {
        if (n[1] < key[n[0]] && !MSTSet[n[0]]) {
          key[n[0]] = n[1];
          parent[n[0]] = minKey;
        }
      }
    }

    int ans = 0;
    for (auto w : key)
      ans += w;

    return ans;
  }
};