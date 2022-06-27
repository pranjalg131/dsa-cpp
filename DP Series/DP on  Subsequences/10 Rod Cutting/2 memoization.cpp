#include <bits/stdc++.h>
using namespace std;

int helper(int i, int len, int n, vector<int> &price, vector<vector<int>> &dp) {

  if (i == n) {
    if (len == 0)
      return 0;
    else
      return price[len - 1];
  }

  if (len == 0)
    return 0;

  if (dp[i][len] != -1)
    return dp[i][len];

  int notCut = helper(i + 1, len, n, price, dp);
  int cut = INT_MIN;
  if (len >= i + 1)
    cut = price[i] + helper(i, len - (i + 1), n, price, dp);

  return dp[i][len] = max(cut, notCut);
}

int cutRod(vector<int> &price, int n) {
  vector<vector<int>> dp(n, vector<int>(n + 1, -1));

  return helper(0, n, n, price, dp);
}
