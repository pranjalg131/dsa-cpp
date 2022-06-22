#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int helper(int n, vector<int> &dp) {
    if (n == 0)
      return 1;

    if (dp[n] != -1)
      return dp[n];

    int oneStep = helper(n - 1, dp);
    int twoStep = (n > 1) ? helper(n - 2, dp) : 0;

    return dp[n] = oneStep + twoStep;
  }

  int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return helper(n, dp);
  }
};