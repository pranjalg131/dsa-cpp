#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *coins, int n, int value) {
  vector<vector<long long int>> dp(n, vector<long long int>(value + 1, 0));

  for (int v = 0; v <= value; v++) {
    if (v % coins[0] == 0) {
      dp[0][v] = 1;
    } else
      dp[0][v] = 0;
  }

  for (int i = 1; i < n; i++) {
    for (int v = 0; v <= value; v++) {
      long long int notTake = dp[i - 1][v];
      long long int take = 0;
      if (v >= coins[i])
        take = dp[i][v - coins[i]];

      dp[i][v] = take + notTake;
    }
  }

  return dp[n - 1][value];
}