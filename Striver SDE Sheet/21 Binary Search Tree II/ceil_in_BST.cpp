#include <bits/stdc++.h>
using namespace std;

template <typename T> class BinaryTreeNode {
public:
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;

  BinaryTreeNode(T data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }

  ~BinaryTreeNode() {
    if (left) {
      delete left;
    }
    if (right) {
      delete right;
    }
  }
};

class Solution {
public:
  int findCeil(BinaryTreeNode<int> *node, int x) {
    BinaryTreeNode<int> *curr = node;

    int ans = -1;
    while (curr) {
      if (curr->data == x)
        return x;

      if (curr->data < x) {
        curr = curr->right;
      } else {
        ans = curr->data;
        curr = curr->left;
      }
    }

    return ans;
  }
};