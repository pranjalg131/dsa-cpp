#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int _merge(vector<int> &nums, int start, int mid, int end,
             vector<int> &temp) {
    int left = start;
    int right = mid;
    int k = start;

    int count = 0;
    int j = mid;

    for (int i = left; i < mid; i++) {
      while (j <= end && nums[i] > 2LL * nums[j]) {
        j++;
      }
      count += (j - mid);
    }

    while (left < mid && right <= end) {
      if (nums[left] <= nums[right]) {
        temp[k++] = nums[left++];
      } else {
        temp[k++] = nums[right++];
      }
    }

    while (left < mid) {
      temp[k++] = nums[left++];
    }

    while (right <= end) {
      temp[k++] = nums[right++];
    }

    for (int i = start; i <= end; i++)
      nums[i] = temp[i];

    return count;
  }

  int countPairs(vector<int> &nums, int start, int end, vector<int> &temp) {
    if (start >= end)
      return 0;

    int mid = (start + end) / 2;
    long long int leftAns = countPairs(nums, start, mid, temp);
    long long int rightAns = countPairs(nums, mid + 1, end, temp);
    long long int mergeCount = _merge(nums, start, mid + 1, end, temp);

    return leftAns + rightAns + mergeCount;
  }

  int reversePairs(vector<int> &nums) {
    vector<int> temp(nums.size());
    return countPairs(nums, 0, nums.size() - 1, temp);
  }
};