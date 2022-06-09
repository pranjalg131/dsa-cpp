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

class Solution {
public:
  bool helper(TreeNode *root, long long min, long long max) {
    if (root == NULL)
      return true;

    if (root->val <= min || root->val >= max)
      return false;

    return helper(root->left, min, root->val) &&
           helper(root->right, root->val, max);
  }

  bool isValidBST(TreeNode *root) { return helper(root, LLONG_MIN, LLONG_MAX); }
};