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
  TreeNode *helper(vector<int> &inorder, int inStart, int inEnd,
                   vector<int> &postorder, int postStart, int postEnd,
                   map<int, int> &rec) {

    if (inStart > inEnd || postStart > postEnd)
      return NULL;

    TreeNode *root = new TreeNode(postorder[postEnd]);

    int inRoot = rec[postorder[postEnd]];
    int numsStart = inRoot - inStart;

    root->left = helper(inorder, inStart, inRoot - 1, postorder, postStart,
                        postStart + numsStart - 1, rec);
    root->right = helper(inorder, inRoot + 1, inEnd, postorder,
                         postStart + numsStart, postEnd - 1, rec);

    return root;
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    map<int, int> rec;

    for (int i = 0; i < inorder.size(); i++)
      rec[inorder[i]] = i;

    TreeNode *root = helper(inorder, 0, inorder.size() - 1, postorder, 0,
                            postorder.size() - 1, rec);

    return root;
  }
};