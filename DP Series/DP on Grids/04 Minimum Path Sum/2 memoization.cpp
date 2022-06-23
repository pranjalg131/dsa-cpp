#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
  int helper(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
    int m = grid.size();
    int n = grid[0].size();

    if (i >= m || j >= n)
      return INT_MAX;

    if (i == m - 1 && j == n - 1) {
      return dp[i][j] = grid[i][j];
    }

    if (dp[i][j] != -1)
      return dp[i][j];

    int rightAns = helper(grid, i, j + 1, dp);
    int downAns = helper(grid, i + 1, j, dp);

    return dp[i][j] = min(rightAns, downAns) + grid[i][j];
  }

public:
  int minPathSum(vector<vector<int>> &grid, int i = 0, int j = 0) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return this->helper(grid, 0, 0, dp);
  }
};