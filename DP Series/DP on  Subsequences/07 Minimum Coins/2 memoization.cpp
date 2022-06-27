#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &num, int x, int i, vector<vector<int>> &dp) {
  int n = num.size();

  if (i == n) {
    if (x == 0)
      return 0;
    else
      return 1e8;
  }

  if (x == 0)
    return 0;

  if (dp[i][x] != -1)
    return dp[i][x];

  int notTake = helper(num, x, i + 1, dp);
  int take = 1e8;
  if (num[i] <= x)
    take = 1 + helper(num, x - num[i], i, dp);

  return dp[i][x] = min(take, notTake);
}

int minimumElements(vector<int> &num, int x) {
  int n = num.size();
  vector<vector<int>> dp(n, vector<int>(x + 1, -1));
  int ans = helper(num, x, 0, dp);

  return (ans == 1e8) ? -1 : ans;
}