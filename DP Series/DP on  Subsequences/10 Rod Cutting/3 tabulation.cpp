#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price, int n) {
  vector<vector<int>> dp(n, vector<int>(n + 1, 0));

  for (int l = 1; l <= n; l++) {
    dp[0][l] = l * price[0];
  }

  for (int i = 1; i < n; i++) {
    for (int l = 0; l <= n; l++) {
      int notCut = dp[i - 1][l];
      int cut = INT_MIN;
      if (l >= (i + 1))
        cut = price[i] + dp[i][l - (i + 1)];

      dp[i][l] = max(cut, notCut);
    }
  }

  return dp[n - 1][n];
}
