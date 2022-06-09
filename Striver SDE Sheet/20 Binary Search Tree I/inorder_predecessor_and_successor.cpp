#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  struct Node *left, *right;
};

class Solution {
public:
  void findPreSuc(Node *root, Node *&pre, Node *&suc, int key) {

    Node *curr = root;

    while (curr) {
      if (curr->key >= key)
        curr = curr->left;
      else {
        pre = curr;
        curr = curr->right;
      }
    }

    curr = root;

    while (curr) {
      if (curr->key <= key)
        curr = curr->right;
      else {
        suc = curr;
        curr = curr->left;
      }
    }
  }
};