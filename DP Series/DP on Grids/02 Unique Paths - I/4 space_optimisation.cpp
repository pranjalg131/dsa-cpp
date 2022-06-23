#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  int uniquePaths(int m, int n, int i = 0, int j = 0) {
    vector<int> prev(n, 0);

    for (int j = 0; j < n; j++) {
      prev[j] = 1;
    }

    // Since we update the state after using the previous one
    // It does not matter , as we are filling from the back, it is confusing
    // just take some time to wrap your head around it.

    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        int leftAns = prev[j + 1];
        int downAns = prev[j];

        prev[j] = leftAns + downAns;
      }
    }

    return prev[0];
  }
};