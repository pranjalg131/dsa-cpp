#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &nums, int n) {
  int sum = 0;
  for (auto el : nums)
    sum += el;

  vector<int> prev(sum + 1, 0);

  prev[0] = 1;
  if (nums[0] <= sum)
    prev[nums[0]] = 1;

  for (int i = 1; i < n; i++) {
    vector<int> curr(sum + 1, 0);
    curr[0] = 1;

    for (int s = 0; s <= sum; s++) {
      int notTake = prev[s];
      int take = 0;
      if (s >= nums[i])
        take = prev[s - nums[i]];

      curr[s] = take || notTake;
    }
    prev = curr;
  }

  int ans = INT_MAX;

  for (int i = 0; i <= sum / 2; i++) {
    if (prev[i]) {
      ans = min(ans, abs(sum - 2 * i));
    }
  }

  return ans;
}
