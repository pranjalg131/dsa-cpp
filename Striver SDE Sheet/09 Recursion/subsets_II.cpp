#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void helper(vector<int> &nums, int idx, vector<int> &currSet,
              vector<vector<int>> &ans) {
    ans.push_back(currSet);
    int n = nums.size();

    for (int i = idx; i < n; i++) {
      if (i != idx && nums[i] == nums[i - 1])
        continue;
      currSet.push_back(nums[i]);
      helper(nums, i + 1, currSet, ans);
      currSet.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> currSet;
    helper(nums, 0, currSet, ans);
    return ans;
  }
};