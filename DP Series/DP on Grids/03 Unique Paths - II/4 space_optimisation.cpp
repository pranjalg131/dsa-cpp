#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  int uniquePathsWithObstacles(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<long long> prev(n, 0);

    int possible = 1;
    for (int j = n - 1; j >= 0; j--) {
      if (grid[m - 1][j] == 1) {
        possible = 0;
      }
      prev[j] = possible;
    }

    possible = prev[n - 1];
    for (int i = m - 2; i >= 0; i--) {

      if (grid[i][n - 1] == 1)
        possible = 0;
      prev[n - 1] = possible;

      for (int j = n - 2; j >= 0; j--) {
        long long rightAns = prev[j + 1];
        long long downAns = prev[j];

        if (grid[i][j] == 0)
          prev[j] = rightAns + downAns;
        else
          prev[j] = 0;
      }
    }

    return prev[0];
  }
};