#include <bits/stdc++.h>
using namespace std;

template <typename T> class TreeNode {
public:
  T data;
  TreeNode<T> *left;
  TreeNode<T> *right;

  TreeNode(T data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }

  ~TreeNode() {
    if (left)
      delete left;
    if (right)
      delete right;
  }
};

class Solution {
public:
  bool isLeafNode(TreeNode<int> *root) { return !root->left && !root->right; }

  void leftTraversal(TreeNode<int> *root, vector<int> &ans) {
    TreeNode<int> *curr = root->left;

    while (curr) {
      if (!isLeafNode(curr)) {
        ans.push_back(curr->data);
      }
      if (curr->left)
        curr = curr->left;
      else
        curr = curr->right;
    }
  }

  void leafNodes(TreeNode<int> *root, vector<int> &ans) {
    if (isLeafNode(root)) {
      ans.push_back(root->data);
      return;
    }

    if (root->left)
      leafNodes(root->left, ans);
    if (root->right)
      leafNodes(root->right, ans);
  }

  void rightTraversal(TreeNode<int> *root, vector<int> &ans) {
    TreeNode<int> *curr = root->right;
    vector<int> temp;

    while (curr) {
      if (!isLeafNode(curr)) {
        temp.push_back(curr->data);
      }
      if (curr->right)
        curr = curr->right;
      else
        curr = curr->left;
    }

    while (temp.size()) {
      ans.push_back(temp.back());
      temp.pop_back();
    }
  }

  vector<int> traverseBoundary(TreeNode<int> *root) {
    if (root == NULL)
      return {};

    vector<int> ans;
    if (!isLeafNode(root))
      ans.push_back(root->data);

    leftTraversal(root, ans);
    leafNodes(root, ans);
    rightTraversal(root, ans);

    return ans;
  }
};