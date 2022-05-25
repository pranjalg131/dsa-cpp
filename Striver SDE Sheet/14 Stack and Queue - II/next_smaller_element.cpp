#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> st;
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && st.top() >= arr[i])
        st.pop();

      if (st.empty()) {
        ans.push_back(-1);
        st.push(arr[i]);
      } else {

        ans.push_back(st.top());
        st.push(arr[i]);
      }
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};