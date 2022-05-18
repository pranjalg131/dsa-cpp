#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  struct Node *bottom;

  Node(int x) {
    data = x;
    next = NULL;
    bottom = NULL;
  }
};

class Solution {
  Node *flatten(Node *root) {
    if (root->next == NULL) {
      return root;
    }

    Node *merged = flatten(root->next);

    Node *res = new Node(0);
    Node *temp = res;

    Node *p = root, *q = merged;

    while (p != NULL && q != NULL) {
      if (p->data < q->data) {
        temp->bottom = p;
        p = p->bottom;
        temp = temp->bottom;
      } else {
        temp->bottom = q;
        q = q->bottom;
        temp = temp->bottom;
      }
    }

    while (p != NULL) {
      temp->bottom = p;
      temp = temp->bottom;
      p = p->bottom;
    }

    while (q != NULL) {
      temp->bottom = q;
      temp = temp->bottom;
      q = q->bottom;
    }

    return res->bottom;
  }
};