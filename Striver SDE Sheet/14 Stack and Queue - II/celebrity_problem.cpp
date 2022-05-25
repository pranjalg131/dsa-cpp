#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool knows(int a, int b) {
    return true;
  } // already built in function. demo implementation.

  int findCelebrity(int n) {
    stack<int> st;

    for (int i = 0; i < n; i++)
      st.push(i);

    while (st.size() > 1) {
      int a = st.top();
      st.pop();
      int b = st.top();
      st.pop();
      if (knows(a, b))
        st.push(b);
      else
        st.push(a);
    }

    int ans = st.top();

    for (int i = 0; i < n; i++) {
      if (i != ans && (knows(ans, i) || !knows(i, ans))) {
        return -1;
      }
    }

    return ans;
  }
};