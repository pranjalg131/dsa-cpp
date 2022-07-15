#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    // When sorted, this becomes longest divisible subsequence
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);
    vector<int> hash(n, 0);

    for (int i = 1; i < n; i++) {
      hash[i] = i;
      for (int j = 1; i - j >= 0; j++) {
        if (nums[i] % nums[i - j] == 0 && dp[i] < dp[i - j] + 1) {
          dp[i] = dp[i - j] + 1;
          hash[i] = i - j;
        }
      }
    }

    int ans = 1;
    int idx = 0;
    for (int i = 0; i < n; i++) {
      if (dp[i] > ans) {
        ans = dp[i];
        idx = i;
      }
    }

    vector<int> temp;
    temp.push_back(nums[idx]);
    while (idx != hash[idx]) {
      idx = hash[idx];
      temp.push_back(nums[idx]);
    }

    reverse(temp.begin(), temp.end());
    return temp;
  }
};