#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights) {
  int prev2, prev;
  prev2 = prev = 0;

  for (int i = 2; i <= n; i++) {
    int oneJump = abs(heights[i - 1] - heights[i - 2]) + prev;
    int twoJump = INT_MAX;
    if (i > 2)
      twoJump = abs(heights[i - 1] - heights[i - 3]) + prev2;

    int curr = min(oneJump, twoJump);
    prev2 = prev;
    prev = curr;
  }

  return prev;
}