#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minChar(string str) {
    int n = str.size();
    int i = n - 1;

    while (i >= 0) {
      if (str[0] != str[i])
        i--;
      else {
        int l = 0, r = i;
        while (r > l + 1 and str[l] == str[r]) {
          l++;
          r--;
        }
        if (l == r or (r == l + 1 and str[l] == str[r]))
          return (n - i - 1);
        else
          i = r;
      }
    }
  }
};