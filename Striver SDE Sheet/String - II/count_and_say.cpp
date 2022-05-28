#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string countAndSay(int n, string s = "1") {
    if (n == 1)
      return s;

    int i = 0, j;
    int len = s.size();
    string res = "";

    while (i < len) {
      int j = i;

      while (i < len && s[j] == s[i])
        i++;

      res += to_string(i - j) + s[j];
    }

    return countAndSay(n - 1, res);
  }
};