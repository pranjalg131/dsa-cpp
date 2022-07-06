#include <bits/stdc++.h>
using namespace std;

int lcs(string &s, string &t) {
  int m = s.size();
  int n = t.size();

  vector<int> prev(n + 1, 0);

  int ans = 0;
  for (int i = 1; i <= m; i++) {
    vector<int> curr(n + 1, 0);
    for (int j = 1; j <= n; j++) {
      if (s[i - 1] == t[j - 1]) {
        curr[j] = 1 + prev[j - 1];
        ans = max(ans, curr[j]);
      }
    }
    prev = curr;
  }

  return ans;
}