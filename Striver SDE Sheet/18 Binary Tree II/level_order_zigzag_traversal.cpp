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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (root == NULL)
      return {};

    vector<vector<int>> ans;
    queue<TreeNode *> Q;
    Q.push(root);

    bool flag = false;

    while (!Q.empty()) {
      vector<int> level;
      int k = Q.size();

      for (int i = 0; i < k; i++) {
        TreeNode *curr = Q.front();
        Q.pop();

        level.push_back(curr->val);

        if (curr->left)
          Q.push(curr->left);
        if (curr->right)
          Q.push(curr->right);
      }

      if (flag) {
        reverse(level.begin(), level.end());
      }

      ans.push_back(level);
      flag = !flag;
    }

    return ans;
  }
};