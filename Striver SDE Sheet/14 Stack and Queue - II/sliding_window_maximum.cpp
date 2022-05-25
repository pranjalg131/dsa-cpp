#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> Q;
    vector<int> ans;

    int j = 0;
    int i = 0;
    while (j < k) {
      while (!Q.empty() && nums[Q.back()] < nums[j])
        Q.pop_back();
      Q.push_back(j);
      j++;
    }
    j--;

    ans.push_back(nums[Q.front()]);

    while (j < nums.size()) {
      i++;
      j++;
      if (j >= nums.size())
        break;
      while (!Q.empty() && Q.front() < i)
        Q.pop_front();
      while (!Q.empty() && nums[Q.back()] < nums[j])
        Q.pop_back();
      Q.push_back(j);
      ans.push_back(nums[Q.front()]);
    }

    return ans;
  }
};