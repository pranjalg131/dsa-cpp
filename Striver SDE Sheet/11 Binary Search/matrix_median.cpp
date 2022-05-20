#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int getElements(int num, vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int ans = 0;

    for (int i = 0; i < m; i++) {
      int low = 0;
      int high = n - 1;

      while (low <= high) {
        int mid = (low + high) / 2;
        if (matrix[i][mid] <= num)
          low = mid + 1;
        else
          high = mid - 1;
      }
      ans += low;
    }
    return ans;
  }

  int getMedian(vector<vector<int>> &matrix) {
    int low = 1;
    int high = 1e9;

    int m = matrix.size();
    int n = matrix[0].size();

    int safeElements = (m * n) / 2;

    while (low <= high) {
      int mid = (low + high) / 2;
      if (getElements(mid, matrix) <= safeElements) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
};