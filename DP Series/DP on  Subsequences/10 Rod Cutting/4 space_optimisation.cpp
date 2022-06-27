#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price, int n) {
  vector<int> prev(n + 1, 0);

  for (int l = 1; l <= n; l++) {
    prev[l] = l * price[0];
  }

  for (int i = 1; i < n; i++) {
    vector<int> curr(n + 1, 0);
    for (int l = 0; l <= n; l++) {
      int notCut = prev[l];
      int cut = INT_MIN;
      if (l >= (i + 1))
        cut = price[i] + curr[l - (i + 1)];

      curr[l] = max(cut, notCut);
    }
    prev = curr;
  }

  return prev[n];
}
