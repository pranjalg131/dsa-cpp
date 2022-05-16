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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1 == NULL || l2 == NULL)
      return NULL;

    ListNode *ans = new ListNode(0);

    ListNode *p = l1, *q = l2;
    int sum = 0;
    int carry = 0;

    ListNode *dummy = ans;

    while (p != NULL && q != NULL) {
      sum = (p->val + q->val + carry);
      carry = sum / 10;

      ans->next = new ListNode(sum % 10);
      ans = ans->next;

      p = p->next;
      q = q->next;
    }

    while (p != NULL) {
      sum = (p->val + carry);
      carry = sum / 10;
      ans->next = new ListNode(sum % 10);
      ans = ans->next;
      p = p->next;
    }

    while (q != NULL) {
      sum = (q->val + carry);
      carry = sum / 10;
      ans->next = new ListNode(sum % 10);
      ans = ans->next;
      q = q->next;
    }

    if (carry != 0) {
      ans->next = new ListNode(carry);
      ans = ans->next;
    }

    return dummy->next;
  }
};