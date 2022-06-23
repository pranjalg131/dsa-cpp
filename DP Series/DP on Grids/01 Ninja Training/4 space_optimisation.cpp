#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points) {

  vector<int> prev(3, 0);
  for (int i = 0; i < 3; i++) {
    prev[i] = points[0][i];
  }

  for (int i = 1; i < n; i++) {
    vector<int> curr(3, 0);
    for (int j = 0; j < 3; j++) {
      int prevAns = INT_MIN;
      for (int k = 0; k < 3; k++) {
        if (k == j)
          continue;
        prevAns = max(prev[k], prevAns);
      }
      curr[j] = prevAns + points[i][j];
    }
    prev = curr;
  }

  int ans = INT_MIN;
  for (int k = 0; k < 3; k++) {
    ans = max(ans, prev[k]);
  }

  return ans;
}