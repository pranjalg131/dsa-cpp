#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int helper(int i, int buy, vector<int> &prices, vector<vector<int>> &dp) {
    if (i == prices.size())
      return 0;

    if (dp[i][buy] != -1)
      return dp[i][buy];

    int profit = 0;

    if (buy) {

      profit = max(-prices[i] + helper(i + 1, 0, prices, dp),
                   0 + helper(i + 1, 1, prices, dp));

    } else {

      profit = max(prices[i] + helper(i + 1, 1, prices, dp),
                   0 + helper(i + 1, 0, prices, dp));
    }

    return dp[i][buy] = profit;
  }

  int maxProfit(vector<int> &prices) {

    int n = prices.size();
    vector<int> ahead(2, 0);

    for (int i = n - 1; i >= 0; i--) {
      vector<int> curr(2, 0);
      for (int buy = 0; buy < 2; buy++) {

        if (buy) {

          curr[buy] = max(-prices[i] + ahead[0], ahead[1]);

        } else {

          curr[buy] = max(prices[i] + ahead[1], ahead[0]);
        }
      }
      ahead = curr;
    }

    return ahead[1];

    // return helper(0, 1, prices, dp);
  }
};