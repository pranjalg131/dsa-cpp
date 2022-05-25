#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxMinWindow(vector<int> a, int n) {

    vector<int> left(n, -1), right(n, n);
    vector<int> ans(n + 1, INT_MIN);

    stack<int> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && a[st.top()] >= a[i])
        st.pop();
      if (st.empty())
        left[i] = -1;
      else
        left[i] = st.top();
      st.push(i);
    }

    while (!st.empty())
      st.pop();

    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && a[st.top()] >= a[i])
        st.pop();
      if (st.empty())
        right[i] = n;
      else
        right[i] = st.top();
      st.push(i);
    }

    for (int i = 0; i < n; i++) {
      int currSize = right[i] - left[i] - 1;
      ans[currSize] = max(a[i], ans[currSize]);
    }

    for (int i = n - 1; i >= 0; i--) {
      ans[i] = max(ans[i], ans[i + 1]);
    }

    vector<int> temp;
    copy(ans.begin() + 1, ans.end(), back_inserter(temp));
    return temp;
  }
};