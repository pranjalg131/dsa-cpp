#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0)
      return 1;

    if (n < 0)
      return (1 / x) * myPow(1 / x, -(n + 1));

    if (n & 1) {
      return x * myPow(x, n - 1);
    } else {
      double res = myPow(x, n / 2);
      return res * res;
    }
  }
};