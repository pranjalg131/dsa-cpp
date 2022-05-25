#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *prev;
  Node *next;
  int key;
  int value;
  Node() {
    key = 0;
    value = 0;
    prev = NULL;
    next = NULL;
  }
  Node(int k, int v) {
    prev = NULL;
    next = NULL;
    key = k;
    value = v;
  }
};

class LRUCache {
private:
  Node *head;
  Node *tail;
  int cap;
  unordered_map<int, Node *> rec;

public:
  LRUCache(int capacity) {
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    cap = capacity;
    head->next = tail;
    tail->prev = head;
  }

  void addNode(Node *node) {
    Node *temp = head->next;
    node->next = temp;
    node->prev = head;
    head->next = node;
    temp->prev = node;
  }

  void deleteNode(Node *node) {
    Node *prevNode = node->prev;
    Node *nextNode = node->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
  }

  int get(int key_) {
    if (rec.find(key_) == rec.end())
      return -1;

    Node *currNode = rec[key_];
    int res = currNode->value;
    rec.erase(key_);
    deleteNode(currNode);
    addNode(currNode);
    rec[key_] = head->next;
    return res;
  }

  void put(int key_, int value_) {
    if (rec.find(key_) != rec.end()) {
      Node *existingNode = rec[key_];
      existingNode->value = value_;
      deleteNode(existingNode);
      rec.erase(key_);
      addNode(existingNode);
      rec[key_] = head->next;
    } else {
      if (rec.size() == cap) {
        rec.erase(tail->prev->key);
        deleteNode(tail->prev);
      }

      Node *newNode = new Node(key_, value_);
      addNode(newNode);
      rec[key_] = newNode;
    }
  }
};