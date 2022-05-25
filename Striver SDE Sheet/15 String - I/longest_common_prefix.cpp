#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    sort(strs.begin(), strs.end());
    string ans = strs[0];

    for (int i = 1; i < strs.size(); i++) {
      string currPrefix = "";
      for (int j = 0; j < ans.size(); j++) {
        if (strs[i][j] == ans[j])
          currPrefix += ans[j];
        else
          break;
      }
      ans = currPrefix;
    }

    return ans;
  }
};