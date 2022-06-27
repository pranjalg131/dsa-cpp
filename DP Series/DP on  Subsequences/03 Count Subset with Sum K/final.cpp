#include <bits/stdc++.h>
using namespace std;

int findWays(vector<int> &num, int k) {

  vector<int> prev(k + 1, 0);

  prev[0] = 1;
  if (num[0] <= k)
    prev[num[0]] = 1;

  for (int i = 1; i < num.size(); i++) {
    vector<int> curr(k + 1, 0);
    curr[0] = 1;

    for (int s = 0; s <= k; s++) {
      int notTake = prev[s];
      int take = 0;
      if (s >= num[i])
        take = prev[s - num[i]];

      curr[s] = take + notTake;
    }
    prev = curr;
  }

  return prev[k];
}