#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr, int currSum = 0, int i = 0) {

  if (currSum == k)
    return true;
  if (i == n && currSum == k)
    return true;

  if (i == n || currSum > k)
    return false;

  bool take = subsetSumToK(n, k, arr, currSum + arr[i], i + 1);
  bool notTake = subsetSumToK(n, k, arr, currSum, i + 1);

  return take || notTake;
}