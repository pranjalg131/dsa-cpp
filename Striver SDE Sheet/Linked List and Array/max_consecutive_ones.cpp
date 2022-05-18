#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int ans = 0;
    int count = 0;
    int element = -1;

    for (auto el : nums) {
      if (el == 1) {
        if (element == -1) {
          count = 1;
          element = 1;
        } else
          count++;

        ans = max(count, ans);
      } else {
        element = -1;
        count = 0;
      }
    }

    return ans;
  }
};