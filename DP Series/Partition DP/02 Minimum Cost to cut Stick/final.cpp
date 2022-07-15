#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {

    if (i > j)
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    int cost = 1e9;
    for (int k = i; k <= j; k++) {
      int currCost = (cuts[j + 1] - cuts[i - 1]) + helper(i, k - 1, cuts, dp) +
                     helper(k + 1, j, cuts, dp);
      cost = min(currCost, cost);
    }

    return dp[i][j] = cost;
  }

  int minCost(int s, vector<int> &cuts) {
    int n = cuts.size();
    cuts.push_back(s);
    cuts.push_back(0);
    // int i = 1;
    // int j = n - 2;

    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= n; j++) {
        if (i > j)
          continue;

        int cost = 1e9;
        for (int k = i; k <= j; k++) {
          int currCost =
              (cuts[j + 1] - cuts[i - 1]) + dp[i][k - 1] + dp[k + 1][j];
          cost = min(cost, currCost);
        }
        dp[i][j] = cost;
      }
    }

    return dp[1][n];

    // return helper(i, j, cuts, dp);
  }
};