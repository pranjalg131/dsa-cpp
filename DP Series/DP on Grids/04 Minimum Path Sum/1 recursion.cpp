#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid, int i = 0, int j = 0) {
    int m = grid.size();
    int n = grid[0].size();

    if (i >= m || j >= n)
      return INT_MAX;

    if (i == m - 1 && j == n - 1) {
      return grid[i][j];
    }

    int rightAns = minPathSum(grid, i, j + 1);
    int downAns = minPathSum(grid, i + 1, j);

    return min(rightAns, downAns) + grid[i][j];
  }
};