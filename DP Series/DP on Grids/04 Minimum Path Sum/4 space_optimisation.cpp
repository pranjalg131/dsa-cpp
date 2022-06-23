#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  int minPathSum(vector<vector<int>> &grid, int i = 0, int j = 0) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> prev(n, 0);

    int sum = 0;
    for (int j = n - 1; j >= 0; j--) {
      sum += grid[m - 1][j];
      prev[j] = sum;
    }

    for (int i = m - 2; i >= 0; i--) {
      prev[n - 1] += grid[i][n - 1];
      for (int j = n - 2; j >= 0; j--) {
        int rightAns = prev[j + 1];
        int downAns = prev[j];

        prev[j] = min(rightAns, downAns) + grid[i][j];
      }
    }

    return prev[0];
  }
};