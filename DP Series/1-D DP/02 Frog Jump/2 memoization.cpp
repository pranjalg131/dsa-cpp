#include <bits/stdc++.h>
using namespace std;

int helper(int n, vector<int> &heights, vector<int> &dp) {
  if (n == 1)
    return 0;

  if (dp[n] != -1)
    return dp[n];

  int leftAns =
      abs(heights[n - 1] - heights[n - 2]) + helper(n - 1, heights, dp);
  int rightAns = INT_MAX;
  if (n > 2)
    rightAns =
        abs(heights[n - 1] - heights[n - 3]) + helper(n - 2, heights, dp);

  return dp[n] = min(rightAns, leftAns);
}

int frogJump(int n, vector<int> &heights) {
  vector<int> dp(n + 1, -1);
  return helper(n, heights, dp);
}