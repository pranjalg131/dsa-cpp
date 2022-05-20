#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long int getPartitions(long long int k, vector<int> &time) {
    long long int ans = 1;
    long long int count = 0;
    for (auto el : time) {
      if (count + el <= k)
        count += el;
      else {
        ans++;
        if (el <= k)
          count = el;
        else
          return INT_MAX;
      }
    }

    return ans;
  }

  long long ayushGivesNinjatest(int n, int m, vector<int> time) {
    long long int minEl = INT_MAX;
    long long int sumEl = 0;

    for (long long int el : time) {
      minEl = min(minEl, el);
      sumEl += el;
    }

    long long int low = minEl;
    long long int high = sumEl;

    long long int ans = -1;

    while (low <= high) {
      long long mid = (low + high) / 2;
      long long int parts = getPartitions(mid, time);
      if (parts <= n) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }
};