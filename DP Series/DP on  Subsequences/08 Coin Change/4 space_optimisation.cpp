#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *coins, int n, int value) {
  vector<long long int> prev(value + 1, 0);

  for (int v = 0; v <= value; v++) {
    if (v % coins[0] == 0) {
      prev[v] = 1;
    }
  }

  for (int i = 1; i < n; i++) {
    vector<long long int> curr(value + 1, 0);
    for (int v = 0; v <= value; v++) {
      long long int notTake = prev[v];
      long long int take = 0;
      if (v >= coins[i])
        take = curr[v - coins[i]];

      curr[v] = take + notTake;
    }
    prev = curr;
  }

  return prev[value];
}