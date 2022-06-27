#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> weight, vector<int> value, int n, int maxWeight, int i,
           vector<vector<int>> &dp) {
  if (i < 0)
    return 0;

  if (dp[i][maxWeight] != -1)
    return dp[i][maxWeight];

  int notTake = helper(weight, value, n, maxWeight, i - 1, dp);
  int take = INT_MIN;
  if (weight[i] <= maxWeight)
    take =
        value[i] + helper(weight, value, n, maxWeight - weight[i], i - 1, dp);

  return dp[i][maxWeight] = max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

  return helper(weight, value, n, maxWeight, n - 1, dp);
}