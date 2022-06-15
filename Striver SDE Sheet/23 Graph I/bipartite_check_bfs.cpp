#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool bfs(int s, int parent, int color, vector<int> &colors,
           vector<vector<int>> &graph) {

    queue<pair<int, int>> Q;
    Q.push({s, color});
    colors[s] = color;

    while (!Q.empty()) {
      int curr = Q.front().first;
      int currColor = Q.front().second;
      Q.pop();

      for (auto n : graph[curr]) {
        if (colors[n] == -1) {
          int newColor = (currColor + 1) % 2;
          colors[n] = newColor;
          Q.push({n, newColor});
        } else if (colors[n] == colors[curr])
          return true;
      }
    }

    return false;
  }

  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();

    vector<int> colors(n, -1);

    for (int i = 0; i < n; i++) {
      if (colors[i] == -1) {
        if (bfs(i, -1, 0, colors, graph))
          return false;
      }
    }

    return true;
  }
};