#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int helper(vector<vector<int>> &grid, int i, int j1, int j2,
             vector<vector<vector<int>>> &dp) {

    int m = grid.size();
    int n = grid[0].size();

    if (i >= m || j1 >= n || j2 >= n || j1 < 0 || j2 < 0)
      return INT_MIN;

    if (i == m - 1) {
      if (j1 == j2)
        return grid[i][j1];
      return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
      return dp[i][j1][j2];

    int dy[] = {-1, 0, 1};

    int ans = INT_MIN;

    for (int p = 0; p < 3; p++) {
      for (int q = 0; q < 3; q++) {
        ans = max(ans, helper(grid, i + 1, j1 + dy[p], j2 + dy[q], dp));
      }
    }

    if (j1 == j2)
      return dp[i][j1][j2] = ans + grid[i][j1];

    return dp[i][j1][j2] = ans + grid[i][j1] + grid[i][j2];
  }

  int cherryPickup(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<vector<int>>> dp(m,
                                   vector<vector<int>>(n, vector<int>(n, -1)));

    return helper(grid, 0, 0, n - 1, dp);
  }
};