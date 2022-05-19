#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValidColor(int idx, bool graph[101][101], int n, int color,
                    vector<int> &colors) {
    for (int i = 0; i < n; i++) {
      if (graph[idx][i] && colors[i] == color)
        return false;
    }

    return true;
  }

  bool colorGraph(int idx, int m, int n, vector<int> &colors,
                  bool graph[101][101]) {
    if (idx == n)
      return true;

    for (int i = 0; i < m; i++) {
      if (isValidColor(idx, graph, n, i, colors)) {
        colors[idx] = i;
        if (colorGraph(idx + 1, m, n, colors, graph))
          return true;
        colors[idx] = -1;
      }
    }

    return false;
  }

  bool graphColoring(bool graph[101][101], int m, int n) {

    vector<int> colors(n, -1);

    return colorGraph(0, m, n, colors, graph);
  }
};