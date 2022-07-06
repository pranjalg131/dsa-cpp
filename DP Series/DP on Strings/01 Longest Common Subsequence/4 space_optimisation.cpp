#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestCommonSubsequence(string s, string t) {
    int m = s.size();
    int n = t.size();

    vector<int> prev(n + 1, 0);

    for (int i = 1; i <= m; i++) {
      vector<int> curr(n + 1, 0);
      for (int j = 1; j <= n; j++) {
        if (s[i - 1] == t[j - 1])
          curr[j] = 1 + prev[j - 1];
        else {
          curr[j] = max(curr[j - 1], prev[j]);
        }
      }
      prev = curr;
    }

    return prev[n];
  }
};