#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &grid, int i = 0,
                               int j = 0) {

    int m = grid.size();
    int n = grid[0].size();

    if (i >= m || j >= n || grid[i][j] == 1)
      return 0;

    if (i == m - 1 && j == n - 1 && grid[i][j] == 0)
      return 1;

    int rightAns = uniquePathsWithObstacles(grid, i, j + 1);
    int downAns = uniquePathsWithObstacles(grid, i + 1, j);

    return rightAns + downAns;
  }
};