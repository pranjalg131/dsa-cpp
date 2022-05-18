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
  ListNode *rotateRight(ListNode *head, int k) {
    ListNode *curr = head;

    int size = 0;

    while (curr != NULL) {
      curr = curr->next;
      size++;
    }

    if (size == 0)
      return head;

    k = (k % size);

    curr = head;

    while (k--) {
      curr = curr->next;
    }

    ListNode *prev = head;

    while (curr->next != NULL) {
      prev = prev->next;
      curr = curr->next;
    }

    curr->next = head;
    head = prev->next;
    prev->next = NULL;

    return head;
  }
};