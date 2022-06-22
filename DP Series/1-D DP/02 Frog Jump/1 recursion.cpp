#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights) {
  if (n == 1)
    return 0;

  int leftAns = abs(heights[n - 1] - heights[n - 2]) + frogJump(n - 1, heights);
  int rightAns = INT_MAX;
  if (n > 2)
    rightAns = abs(heights[n - 1] - heights[n - 3]) + frogJump(n - 2, heights);

  return min(rightAns, leftAns);
}