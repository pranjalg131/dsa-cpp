#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    string t = s;
    reverse(s.begin(), s.end());
    return s == t;
  }

  void helper(string s, vector<string> &currSet, vector<vector<string>> &ans) {
    if (s.size() == 0) {
      ans.push_back(currSet);
      return;
    }

    for (int i = 1; i <= s.size(); i++) {
      string curr = s.substr(0, i);
      if (isPalindrome(curr)) {
        currSet.push_back(curr);
        helper(s.substr(i), currSet, ans);
        currSet.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> currSet;
    helper(s, currSet, ans);
    return ans;
  }
};