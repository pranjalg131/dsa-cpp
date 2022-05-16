#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<pair<int, int>> arr;
    for (int i = 0; i < nums.size(); i++) {
      arr.push_back({nums[i], i});
    }

    sort(arr.begin(), arr.end());

    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high) {
      int currSum = arr[low].first + arr[high].first;
      if (currSum == target) {
        return {arr[low].second, arr[high].second};
      } else if (currSum < target) {
        low++;
      } else
        high--;
    }

    return {};
  }
};