#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, bool> rec;

    int i = 0;
    int j = 0;
    int ans = 0;

    while (j < s.size()) {
      if (rec.find(s[j]) != rec.end() && rec[s[j]] == true) {
        while (i <= j && rec[s[j]] == true) {
          rec[s[i]] = false;
          i++;
        }
      }

      rec[s[j]] = true;
      j++;

      int length = (j - i);
      ans = max(ans, length);
    }

    return ans;
  }
};