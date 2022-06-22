#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums, int i = 0) {
    if (i >= nums.size())
      return 0;

    int take = nums[i] + rob(nums, i + 2);
    int notTake = rob(nums, i + 1);

    return max(take, notTake);
  }
};