#include <bits/stdc++.h>
using namespace std;

int helper(int k, int i, int n, vector<vector<int>> &points) {
  if (i == n)
    return 0;

  int ans = INT_MIN;
  for (int j = 0; j < 3; j++) {
    if (j == k)
      continue;

    int currAns = points[i][j] + helper(j, i + 1, n, points);
    ans = max(ans, currAns);
  }

  return ans;
}

int ninjaTraining(int n, vector<vector<int>> &points) {

  int ans = INT_MIN;
  for (int i = 0; i < 3; i++) {
    int currAns = helper(i, 0, n, points);
    ans = max(ans, currAns);
  }

  return ans;
}