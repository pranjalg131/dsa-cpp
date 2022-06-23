#include <bits/stdc++.h>
using namespace std;

int helper(int k, int i, int n, vector<vector<int>> &points,
           vector<vector<int>> &dp) {
  if (i == n)
    return 0;

  if (dp[i][k] != -1)
    return dp[i][k];

  int ans = INT_MIN;
  for (int j = 0; j < 3; j++) {
    if (j == k)
      continue;

    int currAns = points[i][j] + helper(j, i + 1, n, points, dp);
    ans = max(ans, currAns);
  }

  return dp[i][k] = ans;
}

int ninjaTraining(int n, vector<vector<int>> &points) {

  int ans = INT_MIN;
  for (int i = 0; i < 3; i++) {
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    int currAns = helper(i, 0, n, points, dp);
    ans = max(ans, currAns);
  }

  return ans;
}