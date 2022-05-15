#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    bool col_flag = false;
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
      if (matrix[i][0] == 0)
        col_flag = true;
      for (int j = 1; j < cols; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = matrix[0][j] = 0;
        }
      }
    }

    // Traversing backwards now...
    for (int i = rows - 1; i >= 0; i--) {
      for (int j = cols - 1; j >= 1; j--) {
        if (matrix[0][j] == 0 || matrix[i][0] == 0)
          matrix[i][j] = 0;
      }
    }

    // Setting the first column zero , only if it was set by own element.
    if (col_flag) {
      for (int i = 0; i < rows; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};