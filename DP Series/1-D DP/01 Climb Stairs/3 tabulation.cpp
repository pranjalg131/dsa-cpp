#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    vector<int> dp(n + 1);

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
      int oneStep = dp[i - 1];
      int twoStep = (i > 1) ? dp[i - 2] : 0;

      dp[i] = oneStep + twoStep;
    }

    return dp[n];
  }
};