#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

class Solution {
public:
  int countNodes(Node *root) {

    Node *curr = root;
    int ans = 0;

    while (curr) {
      if (curr->left == NULL) {
        ans++;
        curr = curr->right;
      } else {
        Node *prev = curr->left;

        while (prev->right && prev->right != curr) {
          prev = prev->right;
        }

        if (prev->right == NULL) {
          prev->right = curr;
          curr = curr->left;
        } else {
          ans++;
          prev->right = NULL;
          curr = curr->right;
        }
      }
    }
    return ans;
  }

  int kthLargest(Node *root, int K) {
    int total = countNodes(root);
    int actual = total - K + 1;

    // cout << total << " " << actual << endl;

    int ans;
    Node *curr = root;

    while (curr) {
      if (curr->left == NULL) {
        actual--;
        if (actual == 0)
          ans = curr->data;
        curr = curr->right;
      } else {
        Node *prev = curr->left;

        while (prev->right && prev->right != curr) {
          prev = prev->right;
        }

        if (prev->right == NULL) {
          prev->right = curr;
          curr = curr->left;
        } else {
          actual--;
          if (actual == 0)
            ans = curr->data;
          prev->right = NULL;
          curr = curr->right;
        }
      }
    }

    return ans;
  }
};