#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool helper(TreeNode *A, int B, vector<int> &ans) {
    if (A == NULL)
      return false;
    if (A->val == B) {
      ans.push_back(B);
      return true;
    }
    ans.push_back(A->val);
    if (helper(A->left, B, ans))
      return true;
    if (helper(A->right, B, ans))
      return true;
    ans.pop_back();
    return false;
  }

  vector<int> Solution::solve(TreeNode *A, int B) {
    if (A == NULL)
      return {};
    vector<int> ans;
    helper(A, B, ans);

    return ans;
  }
};