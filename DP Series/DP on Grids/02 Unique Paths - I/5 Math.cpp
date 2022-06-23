#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m == 1 || n == 1)
      return 1;

    m--;
    n--;

    if (m < n) { // Swap, so that m is the bigger number
      return uniquePaths(n, m);
    }

    long res = 1;
    int j = 1;
    for (int i = m + 1; i <= m + n; i++, j++) {
      // Instead of taking factorial, keep on multiply & divide
      res *= i;
      res /= j;
    }

    return (int)res;
  }
};