#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkPalindrome(string &s, int i, int j) {
    while (i <= j && s[i] == s[j]) {
      i++;
      j--;
    }

    return i > j;
  }

  int helper(int i, string &s, vector<int> &dp,
             vector<vector<bool>> &isPalindrome) {
    if (i == s.size())
      return 0;

    if (dp[i] != -1)
      return dp[i];

    int cuts = 1e9;
    for (int j = i; j < s.size(); j++) {
      if (isPalindrome[i][j]) {
        int currCuts = 1 + helper(j + 1, s, dp, isPalindrome);
        cuts = min(cuts, currCuts);
      }
    }

    return dp[i] = cuts;
  }

  int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        isPalindrome[i][j] = checkPalindrome(s, i, j);
      }
    }

    vector<int> dp(s.size() + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
      int cuts = 1e9;
      for (int j = i; j < n; j++) {
        if (isPalindrome[i][j]) {
          int currCuts = 1 + dp[j + 1];
          cuts = min(cuts, currCuts);
        }
      }
      dp[i] = cuts;
    }

    return dp[0] - 1;

    return helper(0, s, dp, isPalindrome) - 1;
  }
};