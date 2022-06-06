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
  vector<int> bottomView(Node *root) {
    vector<int> ans;
    if (root == NULL)
      return {};

    queue<pair<Node *, int>> Q;
    map<int, int> rec;
    Q.push({root, 0});

    while (!Q.empty()) {
      pair<Node *, int> curr = Q.front();
      Q.pop();

      rec[curr.second] = curr.first->data;

      if (curr.first->left)
        Q.push({curr.first->left, curr.second - 1});
      if (curr.first->right)
        Q.push({curr.first->right, curr.second + 1});
    }

    for (auto x : rec) {
      ans.push_back(x.second);
    }

    return ans;
  }
};