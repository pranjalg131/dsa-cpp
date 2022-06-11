#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class BSTIterator {
  stack<TreeNode *> st;

public:
  BSTIterator(TreeNode *root) {
    TreeNode *curr = root;
    while (curr) {
      st.push(curr);
      curr = curr->left;
    }
  }

  int next() {
    int ans = st.top()->val;

    TreeNode *curr = st.top()->right;
    st.pop();

    while (curr) {
      st.push(curr);
      curr = curr->left;
    }

    return ans;
  }

  bool hasNext() { return !st.empty(); }
};