#include <bits/stdc++.h>
using namespace std;

template <typename T> class TreeNode {
public:
  T val;
  TreeNode<T> *left;
  TreeNode<T> *right;

  TreeNode(T val) {
    this->val = val;
    left = NULL;
    right = NULL;
  }
};

class Solution {
public:
  int floorInBST(TreeNode<int> *root, int X) {
    TreeNode<int> *curr = root;

    int ans;
    while (curr) {
      if (curr->val == X) {
        return X;
      }

      if (curr->val < X) {
        ans = curr->val;
        curr = curr->right;
      } else if (curr->val > X) {
        curr = curr->left;
      }
    }

    return ans;
  }
};