#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &nums, int currSum = 0, int i = 0) {

  vector<vector<int>> dp(n, vector<int>(k + 1, 0));

  dp[0][0] = 1;
  if (nums[0] <= k)
    dp[0][nums[0]] = 1;

  for (int i = 1; i < n; i++) {
    for (int s = 0; s <= k; s++) {
      int notTake = dp[i - 1][s];
      int take = 0;
      if (s >= nums[i]) {
        take = dp[i - 1][s - nums[i]];
      }

      dp[i][s] = take || notTake;
    }
  }

  return dp[n - 1][k];
}