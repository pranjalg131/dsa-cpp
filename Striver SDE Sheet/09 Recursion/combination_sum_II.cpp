#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void helper(int idx, int sum, int target, vector<int> &currSet,
              vector<int> &candidates, vector<vector<int>> &ans) {
    if (sum > target)
      return;

    if (sum == target) {
      ans.push_back(currSet);
      return;
    }

    int n = candidates.size();
    for (int i = idx; i < n; i++) {
      if (i != idx && candidates[i] == candidates[i - 1])
        continue;
      currSet.push_back(candidates[i]);
      helper(i + 1, sum + candidates[i], target, currSet, candidates, ans);
      currSet.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> currSet;
    sort(candidates.begin(), candidates.end());
    helper(0, 0, target, currSet, candidates, ans);
    return ans;
  }
};