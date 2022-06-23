#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
  int helper(int i, int j, int m, int n, vector<vector<int>> &dp) {
    if (i >= m || j >= n)
      return 0;

    if (i == m - 1 && j == n - 1) {
      return 1;
    }

    if (dp[i][j] != -1)
      return dp[i][j];

    int rightAns = helper(i, j + 1, m, n, dp);
    int downAns = helper(i + 1, j, m, n, dp);

    return dp[i][j] = rightAns + downAns;
  }

public:
  int uniquePaths(int m, int n, int i = 0, int j = 0) {
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return this->helper(i, j, m, n, dp);
  }
};