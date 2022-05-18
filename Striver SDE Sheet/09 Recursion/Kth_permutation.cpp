#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int fact(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++)
      res *= i;
    return res;
  }

  string helper(int n, int k, vector<int> &nums) {
    if (nums.size() == 0)
      return "";

    int size = fact(n - 1);
    int idx = k / size;
    k = k % size;
    string curr = to_string(nums[idx]);
    nums.erase(nums.begin() + idx);
    return curr + helper(n - 1, k, nums);
  }

  string getPermutation(int n, int k) {
    k--;
    string ans;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      nums[i] = i + 1;
    ans = helper(n, k, nums);
    return ans;
  }

  string getPermuationIterative(int n, int k) {
    vector<int> nums;
    int fact = 1;
    for (int i = 1; i < n; i++) {
      fact = fact * i;
      nums.push_back(i);
    }
    nums.push_back(n);

    string ans = "";
    k = k - 1;

    while (true) {
      ans += to_string(nums[k / fact]);
      nums.erase(nums.begin() + (k / fact));
      if (nums.size() == 0)
        break;

      k = k % fact;
      fact = fact / nums.size();
    }

    return ans;
  }
};