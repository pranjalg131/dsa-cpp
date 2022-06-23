#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
  int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {

    int m = grid.size();
    int n = grid[0].size();

    if (i >= m || j >= n || grid[i][j] == 1)
      return 0;

    if (i == m - 1 && j == n - 1 && grid[i][j] == 0)
      return 1;

    if (dp[i][j] != -1)
      return dp[i][j];

    int rightAns = helper(i, j + 1, grid, dp);
    int downAns = helper(i + 1, j, grid, dp);

    return dp[i][j] = rightAns + downAns;
  }

public:
  int uniquePathsWithObstacles(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return this->helper(0, 0, grid, dp);
  }
};