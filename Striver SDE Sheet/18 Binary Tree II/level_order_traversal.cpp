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
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == NULL)
      return {};

    queue<TreeNode *> Q;
    Q.push(root);

    vector<vector<int>> ans;

    while (!Q.empty()) {
      int k = Q.size();
      vector<int> level;
      for (int i = 0; i < k; i++) {
        TreeNode *curr = Q.front();
        Q.pop();

        level.push_back(curr->val);
        if (curr->left)
          Q.push(curr->left);
        if (curr->right)
          Q.push(curr->right);
      }

      ans.push_back(level);
    }

    return ans;
  }
};