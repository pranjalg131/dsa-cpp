#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double multiply(double x, int n) {
    if (n == 0)
      return 1.0;

    if (n < 0)
      return (1 / x) * multiply(1 / x, -(n + 1));

    if (n & 1) {
      return x * multiply(x, n - 1);
    } else {
      double res = multiply(x, n / 2);
      return res * res;
    }
  }

  double nthRoot(int n, long long m) {
    double low = 1;
    double high = m;
    double eps = 1e-8;

    while ((high - low) > eps) {
      double mid = (low + high) / 2.0;
      if (multiply(mid, n) < m)
        low = mid;
      else
        high = mid;
    }
    return low;
  }
};