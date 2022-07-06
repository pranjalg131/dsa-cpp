#include <bits/stdc++.h>
using namespace std;

int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp) {

  if (i == s.size() || j == t.size())
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  if (s[i] == t[j]) {
    return dp[i][j] = 1 + helper(i + 1, j + 1, s, t, dp);
  }

  int ans1 = helper(i + 1, j, s, t, dp);
  int ans2 = helper(i, j + 1, s, t, dp);

  return dp[i][j] = max(ans1, ans2);
}

int lcs(string s, string t) {
  int m = s.size();
  int n = t.size();

  vector<vector<int>> dp(m, vector<int>(n, -1));

  return helper(0, 0, s, t, dp);
}