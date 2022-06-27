#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
  vector<int> prev(w + 1, 0);

  for (int k = weight[0]; k <= w; k++)
    prev[k] = (k / weight[0]) * profit[0];

  for (int i = 1; i < n; i++) {
    vector<int> curr(w + 1, 0);
    for (int k = 0; k <= w; k++) {
      int notTake = prev[k];
      int take = INT_MIN;
      if (k >= weight[i])
        take = profit[i] + curr[k - weight[i]];

      curr[k] = max(take, notTake);
    }
    prev = curr;
  }

  return prev[w];
}
