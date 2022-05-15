#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int adjacentToPeak = -1;

    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        adjacentToPeak = i;
        break;
      }
    }

    if (adjacentToPeak == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }

    for (int i = n - 1; i >= 0; i--) {
      if (nums[i] > nums[adjacentToPeak]) {
        swap(nums[i], nums[adjacentToPeak]);
        break;
      }
    }

    reverse(nums.begin() + adjacentToPeak + 1, nums.end());
  }
};