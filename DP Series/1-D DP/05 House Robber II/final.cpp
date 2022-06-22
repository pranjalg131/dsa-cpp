#include <bits/stdc++.h>
using namespace std;

// The idea here being that you can either take the first house or the last but
// not both at a time. remove them one by one, and it becomes house robber 1.

class Solution {
public:
  int rob_1(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    int prev2 = nums[0];
    int prev = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
      int take = nums[i] + prev2;
      int notTake = prev;

      int curr = max(take, notTake);
      prev2 = prev;
      prev = curr;
    }

    return prev;
  }

  int rob(vector<int> &nums) {

    if (nums.size() == 1)
      return nums[0];

    vector<int> notLast(nums.begin(), nums.end() - 1);
    vector<int> notFirst(nums.begin() + 1, nums.end());

    int ans1 = rob_1(notLast);
    int ans2 = rob_1(notFirst);

    return max(ans1, ans2);
  }
};