#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  pair<int, int> helper(int i, int j, string &s,
                        vector<vector<pair<int, int>>> &dp) {

    if (i == j) {
      if (s[i] == 'T')
        return {1, 0};

      return {0, 1};
    }

    if (dp[i][j] != make_pair(-1, -1))
      return dp[i][j];

    pair<int, int> ans = {0, 0};
    for (int k = i + 1; k < j; k += 2) {
      pair<int, int> leftAns = helper(i, k - 1, s, dp);
      pair<int, int> rightAns = helper(k + 1, j, s, dp);

      int trueCount, falseCount;
      int mod = 1003;

      if (s[k] == '&') {
        trueCount = (leftAns.first * rightAns.first) % mod;
        falseCount = ((leftAns.first * rightAns.second) +
                      (leftAns.second * rightAns.first) +
                      (leftAns.second * rightAns.second)) %
                     mod;
      } else if (s[k] == '|') {
        trueCount = ((leftAns.first * rightAns.second) +
                     (leftAns.second * rightAns.first) +
                     (leftAns.first * rightAns.first)) %
                    mod;
        falseCount = (leftAns.second * rightAns.second) % mod;
      } else {
        trueCount = ((leftAns.first * rightAns.second) +
                     (leftAns.second * rightAns.first)) %
                    mod;
        falseCount = ((leftAns.first * rightAns.first) +
                      (leftAns.second * rightAns.second)) %
                     mod;
      }

      ans.first = (ans.first + trueCount) % mod;
      ans.second = (ans.second + falseCount) % mod;
    }

    return dp[i][j] = ans;
  }

  int countWays(int N, string s) {
    vector<vector<pair<int, int>>> dp(N, vector<pair<int, int>>(N, {0, 0}));

    for (int i = 0; i < N; i += 2) {
      if (s[i] == 'T')
        dp[i][i] = {1, 0};
      else
        dp[i][i] = {0, 1};
    }

    for (int i = N - 1; i >= 0; i--) {
      for (int j = i + 1; j <= N - 1; j++) {
        pair<int, int> ans = {0, 0};
        for (int k = i + 1; k < j; k += 2) {
          pair<int, int> leftAns = dp[i][k - 1];
          pair<int, int> rightAns = dp[k + 1][j];

          int trueCount, falseCount;
          int mod = 1003;

          if (s[k] == '&') {
            trueCount = (leftAns.first * rightAns.first) % mod;
            falseCount = ((leftAns.first * rightAns.second) +
                          (leftAns.second * rightAns.first) +
                          (leftAns.second * rightAns.second)) %
                         mod;
          } else if (s[k] == '|') {
            trueCount = ((leftAns.first * rightAns.second) +
                         (leftAns.second * rightAns.first) +
                         (leftAns.first * rightAns.first)) %
                        mod;
            falseCount = (leftAns.second * rightAns.second) % mod;
          } else {
            trueCount = ((leftAns.first * rightAns.second) +
                         (leftAns.second * rightAns.first)) %
                        mod;
            falseCount = ((leftAns.first * rightAns.first) +
                          (leftAns.second * rightAns.second)) %
                         mod;
          }

          ans.first = (ans.first + trueCount) % mod;
          ans.second = (ans.second + falseCount) % mod;
        }

        dp[i][j] = ans;
      }
    }

    return dp[0][N - 1].first;

    return helper(0, N - 1, s, dp).first;
  }
};