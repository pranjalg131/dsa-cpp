#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  static bool sortBylength(const string &s, const string &t) {
    return s.size() < t.size();
  }

  bool compare(string &s, string &t) {

    if (s.size() - 1 != t.size())
      return false;

    int first = 0, second = 0;

    while (first < s.size()) {
      if (second < t.size() && s[first] == t[second]) {
        first++;
        second++;
      } else {
        first++;
      }
    }
    if (first == s.size() && second == t.size())
      return true;

    return false;
  }

  int longestStrChain(vector<string> &words) {
    int n = words.size();
    sort(words.begin(), words.end(), sortBylength);
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
      for (int j = 1; i - j >= 0; j++) {
        if (compare(words[i], words[i - j]) && dp[i] < dp[i - j] + 1) {
          dp[i] = dp[i - j] + 1;
        }
      }
    }

    int ans = 1;
    for (auto x : dp) {
      ans = max(ans, x);
    }
    return ans;
  }
};