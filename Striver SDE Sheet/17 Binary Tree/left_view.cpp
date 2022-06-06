#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;

  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

class Solution {
  void helper(Node *root, vector<int> &ans, int level) {
    if (root == NULL)
      return;

    if (level == ans.size()) {
      ans.push_back(root->data);
    }

    if (root->left)
      helper(root->left, ans, level + 1);
    if (root->right)
      helper(root->right, ans, level + 1);
  }

  vector<int> leftView(Node *root) {
    vector<int> ans;

    helper(root, ans, 0);

    return ans;
  }
};