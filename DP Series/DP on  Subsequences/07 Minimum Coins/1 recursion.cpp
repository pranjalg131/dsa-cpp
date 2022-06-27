#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &num, int x, int i) {
  int n = num.size();

  if (i == n) {
    if (x == 0)
      return 0;
    else
      return 1e8;
  }

  if (x == 0)
    return 0;

  int notTake = helper(num, x, i + 1);
  int take = 1e8;
  if (num[i] <= x)
    take = 1 + helper(num, x - num[i], i);

  return min(take, notTake);
}

int minimumElements(vector<int> &num, int x) {
  int ans = helper(num, x, 0);

  return (ans == 1e8) ? -1 : ans;
}