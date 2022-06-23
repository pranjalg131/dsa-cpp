#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  int minPathSum(vector<vector<int>> &grid, int i = 0, int j = 0) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    int sum = 0;
    for (int i = m - 1; i >= 0; i--) {
      sum += grid[i][n - 1];
      dp[i][n - 1] = sum;
    }

    sum = 0;
    for (int j = n - 1; j >= 0; j--) {
      sum += grid[m - 1][j];
      dp[m - 1][j] = sum;
    }

    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        int rightAns = dp[i][j + 1];
        int downAns = dp[i + 1][j];

        dp[i][j] = min(rightAns, downAns) + grid[i][j];
      }
    }

    return dp[0][0];
  }
};