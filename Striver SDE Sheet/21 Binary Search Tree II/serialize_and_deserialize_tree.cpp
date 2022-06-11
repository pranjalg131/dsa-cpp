#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string ans = "";

    if (!root)
      return ans;

    queue<TreeNode *> Q;
    Q.push(root);

    while (!Q.empty()) {
      TreeNode *curr = Q.front();
      Q.pop();

      if (curr == NULL) {
        ans += "#,";
      } else {
        ans += to_string(curr->val) + ",";
        Q.push(curr->left);
        Q.push(curr->right);
      }
    }
    ans.pop_back();
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.size() == 0)
      return NULL;

    istringstream ss(data);
    string token;

    getline(ss, token, ',');
    TreeNode *root = new TreeNode(stoi(token));
    queue<TreeNode *> Q;
    Q.push(root);

    while (!Q.empty()) {
      TreeNode *curr = Q.front();
      Q.pop();

      getline(ss, token, ',');
      if (token == "#") {
        curr->left = NULL;
      } else {
        curr->left = new TreeNode(stoi(token));
        Q.push(curr->left);
      }

      getline(ss, token, ',');
      if (token == "#") {
        curr->right = NULL;
      } else {
        curr->right = new TreeNode(stoi(token));
        Q.push(curr->right);
      }
    }

    return root;
  }
};