#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomListWithMap(Node *head) {
    unordered_map<Node *, Node *> rec;

    Node *curr = head;

    while (curr != NULL) {
      Node *copy = new Node(curr->val);
      rec[curr] = copy;
      curr = curr->next;
    }

    curr = head;

    while (curr != NULL) {
      if (curr->next != NULL)
        rec[curr]->next = rec[curr->next];
      if (curr->random != NULL)
        rec[curr]->random = rec[curr->random];

      curr = curr->next;
    }

    return rec[head];
  }

  Node *copyRandomList(Node *head) {
    if (head == NULL)
      return NULL;

    Node *front = head;
    Node *curr = NULL;

    do {
      curr = front;
      front = front->next;

      Node *copy = new Node(curr->val);

      curr->next = copy;
      copy->next = front;
    } while (front != NULL);

    curr = NULL;
    front = head;

    do {
      if (curr == NULL) {
        curr = front;
        front = front->next;
      } else {
        front = front->next->next;
        curr = curr->next->next;
      }

      if (curr->random != NULL)
        front->random = curr->random->next;

    } while (front != NULL && front->next != NULL);

    Node *dummy = new Node(0);

    curr = head;
    front = curr->next;
    dummy->next = front;

    while (front != NULL && front->next != NULL) {
      curr->next = front->next;
      front->next = front->next->next;

      curr = curr->next;
      front = front->next;
    }

    curr->next = NULL;

    return dummy->next;
  }
};