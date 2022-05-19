#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void helper(int idx, vector<bool> &taken, vector<int> &nums,
              vector<int> &currSet, vector<vector<int>> &ans) {
    if (idx == nums.size()) {
      ans.push_back(currSet);
      return;
    }

    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (!taken[i]) {
        currSet.push_back(nums[i]);
        taken[i] = true;
        helper(idx + 1, taken, nums, currSet, ans);
        taken[i] = false;
        currSet.pop_back();
      }
    }
  }

  vector<vector<int>> permute(vector<int> &nums) {
    int n = nums.size();
    vector<bool> taken(n, false);
    vector<int> currSet;
    vector<vector<int>> ans;
    helper(0, taken, nums, currSet, ans);
    return ans;
  }
};