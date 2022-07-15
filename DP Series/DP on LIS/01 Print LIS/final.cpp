#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    vector<int> hash(n, 0);
    for (int i = 0; i < n; i++)
      hash[i] = i;

    for (int i = 1; i < n; i++) {
      for (int j = 1; i - j >= 0; j++) {
        if (nums[i - j] < nums[i] && (dp[i - j] + 1) > dp[i]) {
          hash[i] = i - j;
          dp[i] = dp[i - j] + 1;
        }
      }
    }
    int idx = 0;
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (dp[i] > ans) {
        idx = i;
        ans = dp[i];
      }
    }

    // This is for printing LIS
    vector<int> lis;
    lis.push_back(nums[idx]);
    while (hash[idx] != idx) {
      idx = hash[idx];
      lis.push_back(nums[idx]);
    }

    reverse(lis.begin(), lis.end());

    for (auto x : lis)
      cout << x << " ";

    return ans;
  }
};