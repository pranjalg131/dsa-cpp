#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void helper(int idx, int sum, vector<int> &candidates, vector<int> &currSet,
              int target, vector<vector<int>> &ans) {
    if (sum == target) {
      ans.push_back(currSet);
      return;
    }

    if (sum > target)
      return;

    for (int i = idx; i < candidates.size(); i++) {
      currSet.push_back(candidates[i]);
      helper(i, sum + candidates[i], candidates, currSet, target, ans);
      currSet.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> currSet;
    helper(0, 0, candidates, currSet, target, ans);
    return ans;
  }
};