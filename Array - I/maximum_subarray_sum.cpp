#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int maxSum = INT_MIN;
    int currSum = 0;

    for (auto el : nums) {
      currSum += el;
      maxSum = max(currSum, maxSum);
      if (currSum < 0)
        currSum = 0;
    }

    return maxSum;
  }

  int maxSubArrayDP(vector<int> &nums) {

    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int maxSum = dp[0];

    for (int i = 1; i < n; i++) {
      dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
      maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
  }
};