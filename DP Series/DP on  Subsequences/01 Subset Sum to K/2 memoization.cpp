#include <bits/stdc++.h>
using namespace std;

bool helper(int n, int k, vector<int> &arr, int currSum, int i,
            vector<vector<int>> &dp) {
  if (currSum == k)
    return true;
  if (i == n && currSum == k)
    return true;

  if (i == n || currSum > k)
    return false;

  if (dp[i][currSum] != -1)
    return dp[i][currSum];

  bool take = helper(n, k, arr, currSum + arr[i], i + 1, dp);
  bool notTake = helper(n, k, arr, currSum, i + 1, dp);

  return dp[i][currSum] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr, int currSum = 0, int i = 0) {

  vector<vector<int>> dp(n, vector<int>(k + 1, -1));
  return helper(n, k, arr, 0, 0, dp);
}