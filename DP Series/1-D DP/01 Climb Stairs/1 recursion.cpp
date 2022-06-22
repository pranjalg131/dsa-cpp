#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n == 0)
      return 1;

    int oneStep = climbStairs(n - 1);
    int twoStep = (n > 1) ? climbStairs(n - 2) : 0;

    return oneStep + twoStep;
  }
};