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

class NodeValue {
public:
  int maxNode, minNode;
  long long int maxSum;

  NodeValue(int minNode, int maxNode, long long int maxSum) {
    this->minNode = minNode;
    this->maxNode = maxNode;
    this->maxSum = maxSum;
  }
};

class Solution {
public:
  NodeValue helper(TreeNode *root, long long int &ans) {

    if (!root) {
      return NodeValue(INT_MAX, INT_MIN, 0);
    }

    auto leftAns = helper(root->left, ans);
    auto rightAns = helper(root->right, ans);

    if (leftAns.maxNode < root->val && root->val < rightAns.minNode) {
      long long int currSum = root->val + leftAns.maxSum + rightAns.maxSum;
      ans = max(ans, currSum);
      return NodeValue(min(leftAns.minNode, root->val),
                       max(rightAns.maxNode, root->val), currSum);
    } else {
      long long int maxSum = max(leftAns.maxSum, rightAns.maxSum);
      return NodeValue(INT_MIN, INT_MAX, maxSum);
    }
  }

  int maxSumBST(TreeNode *root) {
    long long int ans = 0;
    helper(root, ans);
    return ans;
  }
};