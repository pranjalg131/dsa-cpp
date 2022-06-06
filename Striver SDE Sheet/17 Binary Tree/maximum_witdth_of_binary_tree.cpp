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
  int widthOfBinaryTree(TreeNode *root) {
    if (root == NULL)
      return 0;

    long long int ans = 0;
    queue<pair<TreeNode *, int>> Q;
    Q.push({root, 0});

    while (!Q.empty()) {

      int k = Q.size();
      int first, last;
      int lmin = Q.front().second;

      for (int i = 0; i < k; i++) {

        TreeNode *node = Q.front().first;
        int idx = Q.front().second;
        Q.pop();

        if (i == 0)
          first = idx - lmin;
        if (i == k - 1)
          last = idx - lmin;

        if (node->left)
          Q.push({node->left, (long)2 * idx + 1});
        if (node->right)
          Q.push({node->right, (long)2 * idx + 2});
      }

      ans = max(ans, (long long)last - first + 1);
    }

    return ans;
  }
};