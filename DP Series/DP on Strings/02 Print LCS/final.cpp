#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t) {
  int m = s.size();
  int n = t.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i - 1] == t[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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
      int ans1 = dp[i - 1][j];
      int ans2 = dp[i][j - 1];

      if (ans1 > ans2) {
        i--;
      } else {
        j--;
      }
    }
  }

  //     cout << ans << endl;

  return ans.size();
}