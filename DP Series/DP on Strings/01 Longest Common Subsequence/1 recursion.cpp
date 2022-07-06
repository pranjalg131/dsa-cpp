#include <bits/stdc++.h>
using namespace std;

int helper(int i, int j, string &s, string &t) {

  if (i == s.size() || j == t.size())
    return 0;

  if (s[i] == t[j]) {
    return 1 + helper(i + 1, j + 1, s, t);
  }

  int ans1 = helper(i + 1, j, s, t);
  int ans2 = helper(i, j + 1, s, t);

  return max(ans1, ans2);
}

int lcs(string s, string t) { return helper(0, 0, s, t); }