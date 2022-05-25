#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long int readNums(int i, string &s, bool flag) {
    int l = i;
    int n = s.size();
    long long int ans = 0;

    while (l < n - 1 && s[l] == '0')
      l++;

    while (i < n && (s[i] - '0') >= 0 && (s[i] - '0') < 10) {
      i++;
    }
    int r = i - 1;
    long long int place = 1;
    for (int k = r; k >= l; k--) {
      ans += (flag) ? -1 * (s[k] - '0') * place : (s[k] - '0') * place;
      if (ans > INT_MAX || place > INT_MAX && !flag)
        return INT_MAX;
      if (ans < INT_MIN || place > INT_MAX && flag)
        return INT_MIN;
      place *= 10;
    }
    return ans;
  }

  int myAtoi(string s) {
    long long ans = 0;
    int n = s.size();

    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == ' ')
        continue;
      if (!(s[i] - '0' >= 0 && s[i] - '0' <= 9) && (s[i] != '+' && s[i] != '-'))
        break;
      if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
        ans = readNums(i, s, flag);
        break;
      };

      if (s[i] == '+') {
        ans = readNums(i + 1, s, flag);
        break;
      }

      if (s[i] == '-') {
        flag = true;
        ans = readNums(i + 1, s, flag);
        break;
      }
    }

    return ans;
  }
};