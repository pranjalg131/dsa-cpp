#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int cherryPickup(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> prev(n, vector<int>(n, 0));

    for (int j1 = 0; j1 < n; j1++) {
      for (int j2 = 0; j2 < n; j2++) {
        if (j1 == j2)
          prev[j1][j2] = grid[m - 1][j1];
        else
          prev[j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
      }
    }

    int dj[] = {-1, 0, 1};

    for (int i = m - 2; i >= 0; i--) {
      vector<vector<int>> curr(n, vector<int>(n, 0));
      for (int j1 = 0; j1 < n; j1++) {
        for (int j2 = 0; j2 < n; j2++) {

          int ans = 0;

          for (int p = 0; p < 3; p++) {
            for (int q = 0; q < 3; q++) {
              if ((j1 + dj[p] >= 0 && j1 + dj[p] < n) &&
                  (j2 + dj[q] >= 0 && j2 + dj[q] < n))
                ans = max(ans, prev[j1 + dj[p]][j2 + dj[q]]);
            }
          }

          if (j1 == j2)
            curr[j1][j2] = ans + grid[i][j1];
          else
            curr[j1][j2] = ans + grid[i][j1] + grid[i][j2];
        }
      }
      prev = curr;
    }

    return prev[0][n - 1];
  }
};