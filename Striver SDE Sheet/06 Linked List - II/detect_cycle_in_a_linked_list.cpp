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
  bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL)
      return false;

    ListNode *slow = head, *fast = head;

    do {
      slow = slow->next;
      fast = fast->next->next;
    } while (slow != NULL && fast != NULL && fast->next != NULL &&
             slow != fast);

    if (slow == fast)
      return true;

    return false;
  }
};