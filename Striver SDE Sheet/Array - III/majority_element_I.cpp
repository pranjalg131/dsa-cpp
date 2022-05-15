#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int ans;
    int count = 0;

    for (auto el : nums) {
      if (count == 0) {
        count = 1;
        ans = el;
      } else if (el == ans)
        count++;
      else
        count--;
    }

    return ans;
  }
};