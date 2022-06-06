#include <bits/stdc++.h>
using namespace std;

template <typename T> class BinaryTreeNode {
public:
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;

  BinaryTreeNode(T data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

class Solution {
public:
  vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root) {
    if (root == NULL)
      return {};
    vector<vector<int>> ans;
    ans.push_back({});
    ans.push_back({});
    ans.push_back({});

    stack<pair<BinaryTreeNode<int> *, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
      pair<BinaryTreeNode<int> *, int> curr = st.top();
      st.pop();

      if (curr.second == 1) {
        ans[1].push_back(curr.first->data);
        st.push({curr.first, curr.second + 1});
        if (curr.first->left)
          st.push({curr.first->left, 1});

      } else if (curr.second == 2) {
        ans[0].push_back(curr.first->data);
        st.push({curr.first, curr.second + 1});
        if (curr.first->right)
          st.push({curr.first->right, 1});
      } else {
        ans[2].push_back(curr.first->data);
      }
    }

    return ans;
  }
};