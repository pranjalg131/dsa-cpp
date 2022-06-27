#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  vector<int> prev(maxWeight + 1, 0);

  for (int w = weight[0]; w <= maxWeight; w++) {
    prev[w] = value[0];
  }

  for (int i = 1; i < n; i++) {
    for (int w = maxWeight; w >= 0; w--) {
      int notTake = prev[w];
      int take = INT_MIN;
      if (weight[i] <= w)
        take = value[i] + prev[w - weight[i]];

      prev[w] = max(take, notTake);
    }
  }

  return prev[maxWeight];
}