#include <bits/stdc++.h>
using namespace std;

long long int helper(int *coins, int n, int value, int i,
                     vector<vector<long long int>> &dp) {

  if (i == n) {
    if (value == 0)
      return 1;
    else
      return 0;
  }

  if (value == 0)
    return 1;

  if (dp[i][value] != -1)
    return dp[i][value];

  long long int notTake = helper(coins, n, value, i + 1, dp);
  long long int take = 0;
  if (coins[i] <= value)
    take = helper(coins, n, value - coins[i], i, dp);

  return dp[i][value] = take + notTake;
}

long countWaysToMakeChange(int *coins, int n, int value) {
  vector<vector<long long int>> dp(n, vector<long long int>(value + 1, -1));

  long long int ans = helper(coins, n, value, 0, dp);

  return ans;
}