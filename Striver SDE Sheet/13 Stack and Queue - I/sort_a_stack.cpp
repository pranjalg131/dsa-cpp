#include <bits/stdc++.h>
using namespace std;

class Solution {
  void sortStack(stack<int> &stack) {
    if (stack.size() == 0)
      return;

    int x = stack.top();
    stack.pop();
    sortStack(stack);
    vector<int> temp;

    while (!stack.empty() && stack.top() > x) {
      temp.push_back(stack.top());
      stack.pop();
    }

    stack.push(x);
    while (temp.size() > 0) {
      int t = temp.back();
      temp.pop_back();
      stack.push(t);
    }
  }
};