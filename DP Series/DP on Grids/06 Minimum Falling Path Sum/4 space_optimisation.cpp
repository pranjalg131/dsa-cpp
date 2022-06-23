#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> prev(n, 0);

    for (int j = 0; j < n; j++) {
      prev[j] = matrix[m - 1][j];
    }

    for (int i = m - 2; i >= 0; i--) {
      vector<int> curr(n, 0);
      for (int j = n - 1; j >= 0; j--) {
        int leftDiag, rightDiag, down;

        leftDiag = rightDiag = down = INT_MAX;

        if (j > 0)
          leftDiag = prev[j - 1];
        if (j < n - 1)
          rightDiag = prev[j + 1];
        down = prev[j];

        curr[j] = min(down, min(leftDiag, rightDiag)) + matrix[i][j];
      }
      prev = curr;
    }

    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
      ans = min(ans, prev[j]);

    return ans;
  }
};