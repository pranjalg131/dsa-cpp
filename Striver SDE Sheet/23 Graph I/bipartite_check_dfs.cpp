#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool dfs(int s, int color, vector<int> &colors, vector<vector<int>> &graph) {
    colors[s] = color;

    for (auto n : graph[s]) {
      int newColor = (color + 1) % 2;

      if (colors[n] == -1) {
        if (dfs(n, newColor, colors, graph))
          return true;
      } else if (colors[n] == colors[s])
        return true;
    }

    return false;
  }

  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();

    vector<int> colors(n, -1);

    for (int i = 0; i < n; i++) {
      if (colors[i] == -1) {
        if (dfs(i, 0, colors, graph))
          return false;
      }
    }

    return true;
  }
};