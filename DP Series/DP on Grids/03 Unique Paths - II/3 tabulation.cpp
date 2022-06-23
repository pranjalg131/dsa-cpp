#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  int uniquePathsWithObstacles(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<long long>> dp(m, vector<long long>(n, 0));

    int possible = 1;
    for (int i = m - 1; i >= 0; i--) {
      if (grid[i][n - 1] == 1) {
        possible = 0;
      }
      dp[i][n - 1] = possible;
    }

    possible = 1;
    for (int j = n - 1; j >= 0; j--) {
      if (grid[m - 1][j] == 1) {
        possible = 0;
      }
      dp[m - 1][j] = possible;
    }

    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        long long rightAns = dp[i][j + 1];
        long long downAns = dp[i + 1][j];

        if (grid[i][j] == 0)
          dp[i][j] = rightAns + downAns;
        else
          dp[i][j] = 0;
      }
    }

    return dp[0][0];
  }
};