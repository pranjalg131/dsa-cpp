#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int helper(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
    if (i > j)
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    int cost = INT_MIN;
    for (int k = i; k <= j; k++) {
      int currCost = (nums[i - 1] * nums[k] * nums[j + 1]) +
                     helper(i, k - 1, nums, dp) + helper(k + 1, j, nums, dp);
      cost = max(currCost, cost);
    }

    return dp[i][j] = cost;
  }

  int maxCoins(vector<int> &nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= n; j++) {
        if (i > j)
          continue;

        int cost = INT_MIN;

        for (int k = i; k <= j; k++) {
          int currCost = (nums[i - 1] * nums[k] * nums[j + 1]) + dp[i][k - 1] +
                         dp[k + 1][j];
          cost = max(cost, currCost);
        }

        dp[i][j] = cost;
      }
    }

    return dp[1][n];

    return helper(1, n, nums, dp);
  }
};