#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int n = nums.size();

    int k = 0;

    for (int i = 0; i < n; i++) {
      while (i < n - 1 && nums[i] == nums[i + 1])
        i++;
      nums[k++] = nums[i];
    }

    return k;
  }
};