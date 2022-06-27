#include <bits/stdc++.h>
using namespace std;

int helper(int i, int n, int w, vector<int> &profit, vector<int> &weight) {

  if (i == n)
    return 0;

  if (w == 0)
    return 0;

  int notTake = helper(i + 1, n, w, profit, weight);
  int take = INT_MIN;
  if (weight[i] <= w)
    take = profit[i] + helper(i, n, w - weight[i], profit, weight);

  return max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
  return helper(0, n, w, profit, weight);
}
