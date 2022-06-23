#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int m = triangle.size();
    vector<int> prev(m);

    for (int j = m - 1; j >= 0; j--) {
      prev[j] = triangle[m - 1][j];
    }

    for (int i = m - 2; i >= 0; i--) {
      vector<int> curr(i + 1, 0);
      for (int j = i; j >= 0; j--) {
        int down = prev[j];
        int diag = prev[j + 1];

        curr[j] = min(down, diag) + triangle[i][j];
      }
      prev = curr;
    }

    return prev[0];
  }
};