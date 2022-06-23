#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
  int helper(vector<vector<int>> &triangle, int i, int j,
             vector<vector<int>> &dp) {
    int m = triangle.size();
    int n = triangle[i].size();

    if (i >= m || j >= n)
      return INT_MAX;

    if (i == m - 1) {
      return triangle[i][j];
    }

    if (dp[i][j] != -1)
      return dp[i][j];

    int down = helper(triangle, i + 1, j, dp);
    int diag = helper(triangle, i + 1, j + 1, dp);

    return dp[i][j] = triangle[i][j] + min(down, diag);
  }

public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int m = triangle.size();
    vector<vector<int>> dp(m);

    for (int i = 0; i < m; i++) {
      dp[i] = vector<int>(i + 1, -1);
    }

    return this->helper(triangle, 0, 0, dp);
  }
};