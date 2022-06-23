#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle, int i = 0, int j = 0) {
    int m = triangle.size();
    int n = triangle[i].size();

    if (i >= m || j >= n)
      return INT_MAX;

    if (i == m - 1) {
      return triangle[i][j];
    }

    int down = minimumTotal(triangle, i + 1, j);
    int diag = minimumTotal(triangle, i + 1, j + 1);

    return triangle[i][j] + min(down, diag);
  }
};