#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxLen(vector<int> &nums, int n) {

    unordered_map<int, int> rec;
    rec[0] = -1;

    int ans = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
      sum += nums[i];
      if (rec.find(sum) != rec.end()) {
        int currSize = (i - rec[sum]);
        ans = max(currSize, ans);
      } else
        rec[sum] = i;
    }

    return ans;
  }
};