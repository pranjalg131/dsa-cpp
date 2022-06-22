#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {

    int twoStep = 0;
    int oneStep = 1;

    for (int i = 1; i <= n; i++) {
      int curr = twoStep + oneStep;
      twoStep = oneStep;
      oneStep = curr;
    }

    return oneStep;
  }
};