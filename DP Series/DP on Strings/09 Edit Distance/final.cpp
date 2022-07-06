#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp) {

    if (i == 0)
      return j;

    if (j == 0)
      return i;

    if (dp[i][j] != -1)
      return dp[i][j];

    if (s[i - 1] == t[j - 1]) {
      return dp[i][j] = helper(i - 1, j - 1, s, t, dp);
    } else {
      int insert, remove, replace;

      insert = 1 + helper(i, j - 1, s, t, dp);
      remove = 1 + helper(i - 1, j, s, t, dp);
      replace = 1 + helper(i - 1, j - 1, s, t, dp);

      return dp[i][j] = min(insert, min(remove, replace));
    }
  }

  int minDistance(string s, string t) {
    int m = s.size();
    int n = t.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    vector<int> prev(n + 1, 0);

    for (int j = 0; j <= n; j++)
      prev[j] = j;

    for (int i = 1; i <= m; i++) {
      vector<int> curr(n + 1, 0);
      curr[0] = i;
      for (int j = 1; j <= n; j++) {
        if (s[i - 1] == t[j - 1])
          curr[j] = prev[j - 1];
        else
          curr[j] = 1 + min(curr[j - 1], min(prev[j], prev[j - 1]));
      }
      prev = curr;
    }

    return prev[n];
    // return helper(m, n, s, t, dp);
  }
};