#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &nums) {

  vector<int> prev(k + 1, 0);

  prev[0] = 1;
  if (nums[0] <= k)
    prev[nums[0]] = 1;

  for (int i = 1; i < n; i++) {
    vector<int> curr(k + 1, 0);
    curr[0] = 1;
    for (int s = 0; s <= k; s++) {
      int notTake = prev[s];
      int take = 0;
      if (s >= nums[i]) {
        take = prev[s - nums[i]];
      }

      curr[s] = take || notTake;
    }
    prev = curr;
  }

  return prev[k];
}