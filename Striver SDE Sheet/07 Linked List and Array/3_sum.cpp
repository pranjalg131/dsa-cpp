#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();

    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
      int j = i + 1;
      int k = n - 1;
      int target = -1 * nums[i];

      while (j < k) {
        if (nums[j] + nums[k] == target) {
          ans.push_back({nums[i], nums[j], nums[k]});

          while (j < k && nums[j] == nums[j + 1])
            j++;
          while (j < k && nums[k - 1] == nums[k])
            k--;

          j++;
          k--;
        } else if (nums[j] + nums[k] < target)
          j++;
        else
          k--;
      }

      while (i < n - 1 && nums[i] == nums[i + 1])
        i++;
    }

    return ans;
  }
};