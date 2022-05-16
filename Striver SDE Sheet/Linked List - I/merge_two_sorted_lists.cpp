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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *ans = new ListNode();
    ListNode *p = list1, *q = list2;

    ListNode *dummy = ans;

    while (p != NULL && q != NULL) {
      if (p->val < q->val) {
        ans->next = p;
        ans = ans->next;
        p = p->next;
      } else {
        ans->next = q;
        ans = ans->next;
        q = q->next;
      }
    }

    while (p != NULL) {
      ans->next = p;
      ans = ans->next;
      p = p->next;
    }

    while (q != NULL) {
      ans->next = q;
      ans = ans->next;
      q = q->next;
    }

    return dummy->next;
  }
};