#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    int n = s.size();
    string ans = "";

    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == ' ')
        continue;
      string word = "";
      while (i >= 0 && s[i] != ' ')
        word += s[i--];
      reverse(word.begin(), word.end());
      if (ans == "") {
        ans += word;
      } else {
        ans += " ";
        ans += word;
      }
    }

    return ans;
  }
};