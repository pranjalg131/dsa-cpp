#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Function to find the shortest distance of all the vertices
  // from the source vertex S.
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> distance(V, INT_MAX);

    pq.push({0, S});
    distance[S] = 0;

    while (!pq.empty()) {
      int currDist = pq.top().first;
      int currNode = pq.top().second;
      pq.pop();

      for (auto n : adj[currNode]) {
        int newDist = currDist + n[1];
        if (newDist < distance[n[0]]) {
          distance[n[0]] = newDist;
          pq.push({newDist, n[0]});
        }
      }
    }

    return distance;
  }
};