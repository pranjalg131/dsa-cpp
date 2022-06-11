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
  bool isReverse = false;

private:
  void pushAll(TreeNode *root) {
    TreeNode *curr = root;
    while (curr) {
      st.push(curr);
      if (isReverse)
        curr = curr->right;
      else
        curr = curr->left;
    }
  }

public:
  BSTIterator(TreeNode *root, bool reverse) {
    isReverse = reverse;
    pushAll(root);
  }

  int next() {
    TreeNode *temp = st.top();
    st.pop();
    int ans = temp->val;

    if (isReverse)
      pushAll(temp->left);
    else
      pushAll(temp->right);

    return ans;
  }

  bool hasNext() { return !st.empty(); }
};

class Solution {
public:
  bool findTarget(TreeNode *root, int k) {
    if (root == NULL)
      return false;

    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next();

    while (i < j) {
      if (i + j == k)
        return true;
      else if (i + j > k)
        j = r.next();
      else
        i = l.next();
    }

    return false;
  }
};