#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int helper(int i, int k, vector<int> &arr, vector<int> &dp) {
    int n = arr.size();
    if (i == n)
      return 0;

    if (dp[i] != -1)
      return dp[i];

    int maxSum = INT_MIN;
    int len = 0, maxEl = INT_MIN;

    for (int j = i; j < min(n, i + k); j++) {
      len++;
      maxEl = max(arr[j], maxEl);

      int currSum = len * maxEl + helper(j + 1, k, arr, dp);
      maxSum = max(currSum, maxSum);
    }

    return dp[i] = maxSum;
  }

  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
      int maxSum = 0;
      int len = 0, maxEl = INT_MIN;

      for (int j = i; j < min(n, i + k); j++) {
        len++;
        maxEl = max(arr[j], maxEl);

        int currSum = maxEl * len + dp[j + 1];
        maxSum = max(currSum, maxSum);
      }
      dp[i] = maxSum;
    }

    return dp[0];
    return helper(0, k, arr, dp);
  }
};