#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void helper(vector<int> &arr, int idx, int sum, vector<int> &ans) {
    if (idx == arr.size()) {
      ans.push_back(sum);
      return;
    }

    sum += arr[idx];
    helper(arr, idx + 1, sum, ans);
    sum -= arr[idx];
    helper(arr, idx + 1, sum, ans);
  }

  vector<int> subsetSums(vector<int> arr, int N) {
    vector<int> ans;
    helper(arr, 0, 0, ans);
    return ans;
  }
};