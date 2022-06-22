#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights) {
  vector<int> dp(n + 1, -1);

  dp[1] = 0;

  for (int i = 2; i <= n; i++) {
    int oneJump = abs(heights[i - 1] - heights[i - 2]) + dp[i - 1];
    int twoJump = INT_MAX;
    if (i > 2)
      twoJump = abs(heights[i - 1] - heights[i - 3]) + dp[i - 2];

    dp[i] = min(oneJump, twoJump);
  }

  return dp[n];
}