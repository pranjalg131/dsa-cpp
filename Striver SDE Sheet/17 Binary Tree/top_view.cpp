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
public:
  vector<int> topView(Node *root) {
    if (root == NULL)
      return {};

    vector<int> ans;
    queue<pair<Node *, int>> Q;
    map<int, int> rec;

    Q.push({root, 0});

    while (!Q.empty()) {

      pair<Node *, int> curr = Q.front();
      Q.pop();

      Node *node = curr.first;

      if (rec.find(curr.second) == rec.end()) {
        rec[curr.second] = node->data;
      }

      if (node->left)
        Q.push({node->left, curr.second - 1});
      if (node->right)
        Q.push({node->right, curr.second + 1});
    }

    for (auto x : rec) {
      ans.push_back(x.second);
    }

    return ans;
  }
};