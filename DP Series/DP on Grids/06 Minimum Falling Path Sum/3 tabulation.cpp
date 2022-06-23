#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int j = 0; j < n; j++) {
      dp[m - 1][j] = matrix[m - 1][j];
    }

    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        int leftDiag, rightDiag, down;

        leftDiag = rightDiag = down = INT_MAX;

        if (j > 0)
          leftDiag = dp[i + 1][j - 1];
        if (j < n - 1)
          rightDiag = dp[i + 1][j + 1];
        down = dp[i + 1][j];

        dp[i][j] = min(down, min(leftDiag, rightDiag)) + matrix[i][j];
      }
    }

    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
      ans = min(ans, dp[0][j]);

    return ans;
  }
};