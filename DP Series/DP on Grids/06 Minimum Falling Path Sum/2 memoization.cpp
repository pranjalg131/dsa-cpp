#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
  int helper(int i, int j, vector<vector<int>> &matrix,
             vector<vector<int>> &dp) {
    int m = matrix.size();
    int n = matrix[0].size();

    if (i >= m || j >= n || j < 0)
      return INT_MAX;

    if (i == m - 1)
      return matrix[i][j];

    if (dp[i][j] != -1)
      return dp[i][j];

    int leftDiag = helper(i + 1, j - 1, matrix, dp);
    int down = helper(i + 1, j, matrix, dp);
    int rightDiag = helper(i + 1, j + 1, matrix, dp);

    return dp[i][j] = min(down, min(leftDiag, rightDiag)) + matrix[i][j];
  }

public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int n = matrix[0].size();

    int ans = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int j = 0; j < n; j++) {
      ans = min(ans, this->helper(0, j, matrix, dp));
    }

    return ans;
  }
};