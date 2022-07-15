#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size();

    vector<pair<int, int>> dp(n, {1, 1});

    for (int i = 1; i < n; i++) {
      for (int j = 1; i - j >= 0; j++) {
        if (nums[i] > nums[i - j]) {
          if (dp[i - j].first + 1 > dp[i].first) {
            dp[i] = {dp[i - j].first + 1, dp[i - j].second};
          } else if (dp[i - j].first + 1 == dp[i].first) {
            dp[i] = {dp[i].first, dp[i].second + dp[i - j].second};
          }
        }
      }
    }

    int maxLength = 1;
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (dp[i].first > maxLength) {
        maxLength = dp[i].first;
        count = dp[i].second;
      } else if (dp[i].first == maxLength) {
        count += dp[i].second;
      }
    }

    return count;
  }
};