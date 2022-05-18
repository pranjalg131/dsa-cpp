#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int subarraysXor(vector<int> &arr, int x) {
    unordered_map<int, int> rec;
    int currXor = 0;
    rec[0]++;

    int ans = 0;

    for (auto el : arr) {
      currXor ^= el;
      int t = currXor ^ x;
      if (rec.find(t) != rec.end())
        ans += rec[t];
      rec[currXor]++;
    }

    return ans;
  }
};