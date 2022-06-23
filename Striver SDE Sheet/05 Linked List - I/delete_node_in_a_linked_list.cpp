#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void deleteNodeLong(ListNode *node) {

    ListNode *prev = NULL;
    while (node->next != NULL) {
      prev = node;
      node->val = node->next->val;
      node = node->next;
    }

    prev->next = NULL;
  }

  void deleteNode(ListNode *node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};