#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *next;
  Node *prev;
  int key;
  int value;
  int freq;

  Node() {
    prev = next = NULL;
    key = value = 0;
    freq = 1;
  }

  Node(int k, int v) {
    prev = next = NULL;
    key = k;
    value = v;
    freq = 1;
  }
};

class List {
public:
  Node *head = new Node();
  Node *tail = new Node();
  int size;

  List() {
    head->next = tail;
    tail->prev = head;
    size = 0;
  }

  void addNode(Node *node) {
    Node *temp = head->next;
    node->prev = head;
    node->next = temp;
    head->next = node;
    temp->prev = node;
    size++;
  }

  void deleteNode(Node *node) {
    Node *prevNode = node->prev;
    Node *nextNode = node->prev;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    size--;
  }
};

class LFUCache {
private:
  unordered_map<int, Node *> rec;
  unordered_map<int, List *> freqMap;
  int maxSize;
  int currSize;
  int minFreq;

  LFUCache(int capacity) {
    maxSize = capacity;
    currSize = 0;
  }

  void updateFreqListMap(Node *node) {
    rec.erase(node->key);
    freqMap[node->freq]->deleteNode(node);
    if (node->freq == minFreq && freqMap[node->freq]->size == 0) {
      minFreq++;
    }

    List *nextHigherFreqList = new List();
    if (freqMap.find(node->freq + 1) != freqMap.end()) {
      nextHigherFreqList = freqMap[node->freq + 1];
    }

    node->freq += 1;
    nextHigherFreqList->addNode(node);
    freqMap[node->freq] = nextHigherFreqList;
    rec[node->key] = node;
  }

  int get(int key_) {
    if (rec.find(key_) == rec.end())
      return -1;

    Node *currNode = rec[key_];
    int res = currNode->value;
    updateFreqListMap(currNode);
    return res;
  }

  void put(int key_, int value_) {
    if (maxSize == 0)
      return;
    if (rec.find(key_) != rec.end()) {
      Node *node = rec[key_];
      node->value = value_;
      updateFreqListMap(node);
    } else {
      if (currSize == maxSize) {
        List *list = freqMap[minFreq];
        rec.erase(list->tail->prev->key);
        list->deleteNode(list->tail->prev);
        currSize--;
      }

      currSize++;
      minFreq = 1;

      List *currList = new List();
      if (freqMap.find(minFreq) != freqMap.end())
        currList = freqMap[minFreq];

      Node *currNode = new Node(key_, value_);
      rec[key_] = currNode;
      currList->addNode(currNode);
      freqMap[minFreq] = currList;
    }
  }
};