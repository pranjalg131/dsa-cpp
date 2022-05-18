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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    ListNode *p = headA;
    ListNode *q = headB;

    int sizeA = 0;
    int sizeB = 0;

    while (p != NULL) {
      p = p->next;
      sizeA++;
    }

    while (q != NULL) {
      q = q->next;
      sizeB++;
    }

    int k = abs(sizeA - sizeB);

    p = sizeA > sizeB ? headA : headB;
    q = sizeA > sizeB ? headB : headA;

    while (k--)
      p = p->next;

    while (p != NULL && q != NULL && p != q) {
      p = p->next;
      q = q->next;
    }

    return p;
  }
};