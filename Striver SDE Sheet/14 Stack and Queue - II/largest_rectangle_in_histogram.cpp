#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> leftBoundary(n), rightBoundary(n);

    stack<int> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && heights[st.top()] >= heights[i])
        st.pop();

      if (st.empty()) {
        leftBoundary[i] = 0;
        st.push(i);
      } else {
        leftBoundary[i] = st.top() + 1;
        st.push(i);
      }
    }

    while (!st.empty())
      st.pop();

    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && heights[st.top()] >= heights[i])
        st.pop();

      if (st.empty()) {
        rightBoundary[i] = n - 1;
        st.push(i);
      } else {
        rightBoundary[i] = st.top() - 1;
        st.push(i);
      }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
      int res = (rightBoundary[i] - leftBoundary[i] + 1) * heights[i];
      ans = max(ans, res);
    }

    return ans;
  }
};