#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int nCr(int n, int r) {
    if (n - r < r)
      r = n - r;
    double res = 1;

    for (int i = 1; i <= r; i++) {
      res = res * (n - r + i) / i;
    }

    return res;
  }

  int uniquePathsWithMath(int m, int n) {
    int total = m + n - 2;
    int r = m - 1;
    return nCr(total, r);
  }

  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = m - 1; i >= 0; i--)
      dp[i][n - 1] = 1;
    for (int j = n - 1; j >= 0; j--)
      dp[m - 1][j] = 1;

    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
      }
    }

    return dp[0][0];
  }
};