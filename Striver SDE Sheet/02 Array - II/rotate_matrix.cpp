#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    // Taking transpose
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    // Reversing each row
    for (int i = 0; i < m; i++) {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};