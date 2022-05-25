#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> rec;
    rec['I'] = 1;
    rec['V'] = 5;
    rec['X'] = 10;
    rec['L'] = 50;
    rec['C'] = 100;
    rec['D'] = 500;
    rec['M'] = 1000;
    int ans = 0;
    int n = s.size();

    for (int i = n - 1; i >= 0; i--) {
      ans += rec[s[i]];
      if (i > 0 && rec[s[i]] > rec[s[i - 1]]) {
        i--;
        ans -= rec[s[i]];
      }
    }

    return ans;
  }
};