#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {

    unordered_map<int, int> rec;
    for (auto el : nums)
      rec[el]++;

    int ans = 0;

    for (auto el : nums) {
      if (rec.find(el - 1) != rec.end())
        continue;
      else {
        int count = 1;
        int curr = el;
        while (rec.find(curr + 1) != rec.end()) {
          curr++;
          count++;
        }
        ans = max(ans, count);
      }
    }

    return ans;
  }
};