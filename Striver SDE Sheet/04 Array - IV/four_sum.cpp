#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {

    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {

        int x = target - nums[i] - nums[j];
        int k = j + 1;
        int l = n - 1;

        while (k < l) {
          if (nums[k] + nums[l] == x) {
            ans.push_back({nums[i], nums[j], nums[k], nums[l]});

            while (k < l && nums[k] == nums[k + 1])
              k++;
            while (k < l && nums[l - 1] == nums[l])
              l--;

            k++;
            l--;
          } else if (nums[k] + nums[l] < x)
            k++;
          else
            l--;
        }

        while (j < n - 1 && nums[j] == nums[j + 1])
          j++;
      }
      while (i < n - 1 && nums[i] == nums[i + 1])
        i++;
    }

    return ans;
  }
};