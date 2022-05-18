#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();

    int i = 0;
    int j = n - 1;

    int maxLeft = 0, maxRight = 0;
    int ans = 0;

    while (i < j) {
      if (height[i] < height[j]) {
        maxLeft = max(height[i], maxLeft);
        ans += maxLeft - height[i];
        i++;
      } else {
        maxRight = max(height[j], maxRight);
        ans += maxRight - height[j];
        j--;
      }
    }

    return ans;
  }
};