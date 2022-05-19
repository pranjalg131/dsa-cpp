#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(string word, vector<string> &words) {
    for (auto el : words) {
      if (el == word)
        return true;
    }

    return false;
  }

  void helper(string s, string currSen, vector<string> &words,
              vector<string> &ans) {
    if (s.size() == 0) {
      ans.push_back(currSen);
      return;
    }

    for (int i = 1; i <= s.size(); i++) {
      string currWord = s.substr(0, i);
      string tempSen = currSen;
      if (isValid(currWord, words)) {
        if (tempSen.size() > 0)
          tempSen += " ";
        tempSen += currWord;
        helper(s.substr(i), tempSen, words, ans);
      }
    }
  }

  vector<string> wordBreak(string &s, vector<string> &words) {
    vector<string> ans;
    string currSen = "";
    helper(s, currSen, words, ans);
    return ans;
  }
};