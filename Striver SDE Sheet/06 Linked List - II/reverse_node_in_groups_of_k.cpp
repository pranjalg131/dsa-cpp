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
  ListNode *reverseKGroup(ListNode *head, int k) {
    int size = 0;
    ListNode *curr = head;

    while (curr != NULL) {
      size++;
      curr = curr->next;
    }

    if (size == 0 || size == 1)
      return head;

    int groups = size / k;
    ListNode *dummy = new ListNode(0);
    ListNode *pre = dummy, *nex = dummy;
    curr = dummy;
    dummy->next = head;

    for (int i = 0; i < groups; i++) {
      curr = pre->next;
      nex = curr->next;
      for (int j = 0; j < k - 1; j++) {
        curr->next = nex->next;
        nex->next = pre->next;
        pre->next = nex;
        nex = curr->next;
      }
      pre = curr;
    }

    return dummy->next;
  }
};