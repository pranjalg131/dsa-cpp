#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int m = triangle.size();
    vector<vector<int>> dp(m);

    for (int i = 0; i < m; i++) {
      dp[i] = vector<int>(i + 1, 0);
    }

    for (int j = m - 1; j >= 0; j--) {
      dp[m - 1][j] = triangle[m - 1][j];
    }

    for (int i = m - 2; i >= 0; i--) {
      for (int j = i; j >= 0; j--) {
        int down = dp[i + 1][j];
        int diag = dp[i + 1][j + 1];

        dp[i][j] = min(down, diag) + triangle[i][j];
      }
    }

    return dp[0][0];
  }
};