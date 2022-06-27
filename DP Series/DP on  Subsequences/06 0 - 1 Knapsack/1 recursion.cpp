#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight,
             int i = 0) {

  if (i == n)
    return 0;

  int notTake = knapsack(weight, value, n, maxWeight, i + 1);
  int take = INT_MIN;
  if (weight[i] <= maxWeight)
    take = value[i] + knapsack(weight, value, n, maxWeight - weight[i], i + 1);

  return max(take, notTake);
}