#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string shortestCommonSupersequence(string s, string t) {
    // Using LCS Concept to print the subsequence.

    int m = s.size();
    int n = t.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s[i - 1] == t[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }

    int i = m;
    int j = n;
    string ans = "";

    while (i > 0 && j > 0) {
      if (s[i - 1] == t[j - 1]) {
        ans += s[i - 1];
        i--;
        j--;
      } else {
        int left = dp[i][j - 1];
        int up = dp[i - 1][j];

        if (up > left) {
          ans += s[i - 1];
          i--;
        } else {
          ans += t[j - 1];
          j--;
        }
      }
    }

    if (i > 0) {
      string leftover = s.substr(0, i);
      reverse(leftover.begin(), leftover.end());
      ans += leftover;
    }

    if (j > 0) {
      string leftover = t.substr(0, j);
      reverse(leftover.begin(), leftover.end());
      ans += leftover;
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};