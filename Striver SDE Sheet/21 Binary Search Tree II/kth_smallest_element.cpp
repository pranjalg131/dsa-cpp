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
  int kthSmallest(TreeNode *root, int k) {

    int ans;

    TreeNode *curr = root;

    while (curr) {
      if (curr->left == NULL) {
        k--;
        if (k == 0)
          ans = curr->val;
        curr = curr->right;
      } else {

        TreeNode *prev = curr->left;

        while (prev->right && prev->right != curr) {
          prev = prev->right;
        }

        if (prev->right == NULL) {
          prev->right = curr;
          curr = curr->left;
        } else {
          prev->right = NULL;
          k--;
          if (k == 0)
            ans = curr->val;
          curr = curr->right;
        }
      }
    }

    return ans;
  }
};