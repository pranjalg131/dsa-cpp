#include <bits/stdc++.h>
using namespace std;

int helper(int i, int n, int w, vector<int> &profit, vector<int> &weight,
           vector<vector<int>> &dp) {

  if (i == n)
    return 0;

  if (w == 0)
    return 0;

  if (dp[i][w] != -1)
    return dp[i][w];

  int notTake = helper(i + 1, n, w, profit, weight, dp);
  int take = INT_MIN;
  if (weight[i] <= w)
    take = profit[i] + helper(i, n, w - weight[i], profit, weight, dp);

  return dp[i][w] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
  vector<vector<int>> dp(n, vector<int>(w + 1, -1));

  return helper(0, n, w, profit, weight, dp);
}
