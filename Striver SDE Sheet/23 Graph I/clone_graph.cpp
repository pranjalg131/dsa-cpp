#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node *helper(Node *node, unordered_map<Node *, Node *> &rec) {
    if (node == NULL)
      return node;

    Node *ans = new Node(node->val);

    rec[node] = ans;

    for (int i = 0; i < node->neighbors.size(); i++) {
      if (rec.find(node->neighbors[i]) == rec.end()) {
        Node *neighbor = helper(node->neighbors[i], rec);
        ans->neighbors.push_back(neighbor);
      } else {
        ans->neighbors.push_back(rec[node->neighbors[i]]);
      }
    }

    return ans;
  }

  Node *cloneGraph(Node *node) {
    unordered_map<Node *, Node *> rec;
    return helper(node, rec);
  }
};