#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int n = nums.size();
    int low = 0, curr = 0;
    int high = n - 1;

    while (curr <= high) {

      if (nums[curr] == 1)
        curr++;
      else if (nums[curr] == 2) {
        swap(nums[curr], nums[high]);
        high--;
      } else if (nums[curr] == 0) {
        swap(nums[curr], nums[low]);
        low++;
        curr++;
      }
    }
  }
};