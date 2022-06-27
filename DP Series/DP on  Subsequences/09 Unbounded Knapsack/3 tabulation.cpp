#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
  vector<vector<int>> dp(n, vector<int>(w + 1, 0));

  for (int k = weight[0]; k <= w; k++)
    dp[0][k] = (k / weight[0]) * profit[0];

  for (int i = 1; i < n; i++) {
    for (int k = 0; k <= w; k++) {
      int notTake = dp[i - 1][k];
      int take = INT_MIN;
      if (k >= weight[i])
        take = profit[i] + dp[i][k - weight[i]];

      dp[i][k] = max(take, notTake);
    }
  }

  return dp[n - 1][w];
}
