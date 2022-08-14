#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int minPrice = prices[0];
    int maxProfit = 0;

    for (auto x : prices) {
      minPrice = min(minPrice, x);
      int profit = x - minPrice;
      maxProfit = max(profit, maxProfit);
    }

    return maxProfit;
  }
};