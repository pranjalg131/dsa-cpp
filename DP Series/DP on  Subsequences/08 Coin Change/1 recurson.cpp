#include <bits/stdc++.h>
using namespace std;

long long int helper(int *coins, int n, int value, int i) {

  if (i == n) {
    if (value == 0)
      return 1;
    else
      return 0;
  }

  if (value == 0)
    return 1;

  long long int notTake = helper(coins, n, value, i + 1);
  long long int take = 0;
  if (coins[i] <= value)
    take = helper(coins, n, value - coins[i], i);

  return take + notTake;
}

long countWaysToMakeChange(int *coins, int n, int value) {
  long long int ans = helper(coins, n, value, 0);
  return ans;
}