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
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    if (root == NULL)
      return {};

    queue<pair<TreeNode *, pair<int, int>>> Q;

    Q.push({root, {0, 0}});
    map<int, map<int, multiset<int>>> rec;

    while (!Q.empty()) {
      TreeNode *node = Q.front().first;
      int v = Q.front().second.first;
      int h = Q.front().second.second;

      Q.pop();

      rec[v][h].insert(node->val);

      if (node->left)
        Q.push({node->left, {v - 1, h + 1}});
      if (node->right)
        Q.push({node->right, {v + 1, h + 1}});
    }

    vector<vector<int>> ans;

    for (auto v : rec) {
      vector<int> line;
      for (auto h : v.second) {
        for (auto it = h.second.begin(); it != h.second.end(); it++) {
          line.push_back(*it);
        }
      }
      ans.push_back(line);
    }

    return ans;
  }
};