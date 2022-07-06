#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool helper(int i, int j, string &s, string &p, vector<vector<int>> &dp) {

    if (j == 0)
      return i == 0;

    if (i == 0) {
      if (p[j - 1] == '*')
        return helper(i, j - 1, s, p, dp);

      return false;
    }

    if (dp[i][j] != -1)
      return dp[i][j];

    if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
      return dp[i][j] = helper(i - 1, j - 1, s, p, dp);
    else if (p[j - 1] == '*') {
      return dp[i][j] =
                 helper(i - 1, j, s, p, dp) || helper(i, j - 1, s, p, dp);
    }

    return dp[i][j] = false;
  }

  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();

    vector<bool> prev(n + 1, false);

    prev[0] = true;

    for (int j = 1; j <= n; j++) {
      if (prev[j - 1] && p[j - 1] == '*')
        prev[j] = true;
    }

    for (int i = 1; i <= m; i++) {
      vector<bool> curr(n + 1, false);
      for (int j = 1; j <= n; j++) {
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
          curr[j] = prev[j - 1];
        else if (p[j - 1] == '*') {
          curr[j] = curr[j - 1] || prev[j];
        }
      }
      prev = curr;
    }

    return prev[n];

    // return helper(m, n, s, p, dp);
  }
};