#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> calcLIS(vector<int> &nums) {

    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
      for (int j = 1; i - j >= 0; j++) {
        if (nums[i] > nums[i - j] && dp[i] < dp[i - j] + 1) {
          dp[i] = dp[i - j] + 1;
        }
      }
    }
    return dp;
  }

  int minimumMountainRemovals(vector<int> &nums) {
    int n = nums.size();
    vector<int> lis = calcLIS(nums);
    reverse(nums.begin(), nums.end());
    vector<int> lds = calcLIS(nums);
    reverse(lds.begin(), lds.end());

    for (auto x : lis)
      cout << x << " ";

    cout << "\n";

    for (auto x : lds)
      cout << x << " ";

    cout << "\n";

    int len = 0;
    for (int i = 0; i < n; i++) {
      if (lis[i] > 1 && lds[i] > 1)
        len = max(len, lis[i] + lds[i] - 1);
    }

    return n - len;
  }
};