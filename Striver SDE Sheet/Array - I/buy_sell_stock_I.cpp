#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (auto el : prices) {
      minPrice = min(minPrice, el);
      int currProfit = el - minPrice;
      maxProfit = max(maxProfit, currProfit);
    }

    return maxProfit;
  }
};