#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string ans = "";
    int n = s.size();

    for (int k = 0; k < n; k++) {
      int l = k, r = k;
      while (l >= 0 && r < n && s[l] == s[r]) {
        l--;
        r++;
      }
      int currSize = r - l - 1;
      if (currSize > ans.size()) {
        ans = s.substr(l + 1, currSize);
      }
    }

    for (int k = 0; k < n - 1; k++) {
      int l = k, r = k + 1;
      while (l >= 0 && r < n && s[l] == s[r]) {
        l--;
        r++;
      }
      int currSize = r - l - 1;
      if (currSize > ans.size()) {
        ans = s.substr(l + 1, currSize);
      }
    }

    return ans;
  }
};