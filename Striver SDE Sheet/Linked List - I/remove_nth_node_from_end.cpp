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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *curr = head;
    for (int i = 1; i < n; i++)
      curr = curr->next;

    ListNode *node = head;
    ListNode *prev = NULL;

    while (curr->next != NULL) {
      curr = curr->next;
      prev = node;
      node = node->next;
    }

    if (node == head)
      return node->next;

    prev->next = node->next;

    return head;
  }
};