#include <bits/stdc++.h>
using namespace std;

int helper(int i, int len, int n, vector<int> &price) {

  if (i == n) {
    if (len == 0)
      return 0;
    else
      return price[len - 1];
  }

  if (len == 0)
    return 0;

  int notCut = helper(i + 1, len, n, price);
  int cut = INT_MIN;
  if (len >= i + 1)
    cut = price[i] + helper(i, len - (i + 1), n, price);

  return max(cut, notCut);
}

int cutRod(vector<int> &price, int n) { return helper(0, n, n, price); }
