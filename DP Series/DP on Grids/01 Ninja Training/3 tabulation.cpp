#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points) {

  vector<vector<int>> dp(n, vector<int>(3, 0));

  for (int i = 0; i < 3; i++) {
    dp[0][i] = points[0][i];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      int prevAns = INT_MIN;
      for (int k = 0; k < 3; k++) {
        if (k == j)
          continue;
        prevAns = max(dp[i - 1][k], prevAns);
      }
      dp[i][j] = prevAns + points[i][j];
    }
  }

  int ans = INT_MIN;
  for (int k = 0; k < 3; k++) {
    ans = max(ans, dp[n - 1][k]);
  }

  return ans;
}