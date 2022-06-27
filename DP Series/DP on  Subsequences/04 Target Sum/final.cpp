#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int d) {
    int sum = 0;
    for (auto el : nums)
      sum += el;

    if (sum - d < 0 || (sum - d) % 2)
      return 0;

    int k = (sum - d) / 2;
    int n = nums.size();

    vector<int> prev(k + 1, 0);

    if (nums[0] == 0)
      prev[0] = 2;
    else
      prev[0] = 1;

    if (nums[0] != 0 && nums[0] <= k)
      prev[nums[0]] = 1;

    for (int i = 1; i < n; i++) {
      vector<int> curr(k + 1, 0);
      curr[0] = 1;

      for (int s = 0; s <= k; s++) {
        int notTake = prev[s];
        int take = 0;
        if (s >= nums[i])
          take = prev[s - nums[i]];

        curr[s] = take + notTake;
      }
      prev = curr;
    }

    return prev[k];
  }
};