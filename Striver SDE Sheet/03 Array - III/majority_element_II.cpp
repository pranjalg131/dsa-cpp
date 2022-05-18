#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int n = nums.size();
    int first = -1, second = -1;
    int firstCount = 0, secondCount = 0;

    for (auto el : nums) {
      if (el == first)
        firstCount++;
      else if (el == second)
        secondCount++;
      else if (firstCount == 0) {
        first = el;
        firstCount = 1;
      } else if (secondCount == 0) {
        second = el;
        secondCount = 1;
      } else {
        firstCount--;
        secondCount--;
      }
    }

    firstCount = secondCount = 0;

    for (auto el : nums) {
      if (el == first)
        firstCount++;
      if (el == second)
        secondCount++;
    }

    vector<int> ans;
    if (firstCount > (n / 3))
      ans.push_back(first);

    if (secondCount > (n / 3) && second != first)
      ans.push_back(second);

    return ans;
  }
};