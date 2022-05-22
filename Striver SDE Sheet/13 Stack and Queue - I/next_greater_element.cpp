#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> rec;
    stack<int> st;

    for (int i = 0; i < nums2.size(); i++) {
      rec[nums2[i]] = i;
    }

    vector<int> ans(nums2.size());

    for (int i = nums2.size() - 1; i >= 0; i--) {
      while (!st.empty() && st.top() < nums2[i])
        st.pop();
      if (st.empty()) {
        ans[i] = -1;
        st.push(nums2[i]);
        continue;
      }
      ans[i] = st.top();
      st.push(nums2[i]);
    }

    vector<int> finalAns;
    for (int i = 0; i < nums1.size(); i++) {
      int idx = rec[nums1[i]];
      finalAns.push_back(ans[idx]);
    }

    return finalAns;
  }
};