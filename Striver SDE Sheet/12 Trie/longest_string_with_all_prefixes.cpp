#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *links[26];
  bool flag = false;
  bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
  void put(char ch, Node *node) { links[ch - 'a'] = node; }
  Node *get(char ch) { return links[ch - 'a']; }
  bool setEnd() { flag = true; }
  bool isEnd() { return flag; }
};

class Trie {
private:
  Node *root;

public:
  Trie() { root = new Node(); }

  void insert(string word) {
    Node *node = root;

    for (int i = 0; i < word.size(); i++) {
      if (!node->containsKey(word[i])) {
        node->put(word[i], new Node());
      }
      node = node->get(word[i]);
    }

    node->setEnd();
  }

  bool search(string word) {
    Node *node = root;

    for (int i = 0; i < word.size(); i++) {
      if (!node->containsKey(word[i])) {
        return false;
      }
      node = node->get(word[i]);
    }

    return node->isEnd();
  }

  bool startsWith(string prefix) {
    Node *node = root;

    for (int i = 0; i < prefix.size(); i++) {
      if (!node->containsKey(prefix[i])) {
        return false;
      }
      node = node->get(prefix[i]);
    }
    return true;
  }
};

bool hasAllPrefixes(Trie *T, string &word) {
  int n = word.size();
  for (int i = 1; i <= n; i++) {
    if (!T->search(word.substr(0, i))) {
      return false;
    }
  }

  return true;
}

string completeString(int n, vector<string> &a) {
  Trie *T = new Trie();
  for (int i = 0; i < n; i++) {
    T->insert(a[i]);
  }

  string ans = "";
  for (int i = 0; i < n; i++) {
    if (hasAllPrefixes(T, a[i])) {
      if (a[i].size() > ans.size())
        ans = a[i];
      if (a[i].size() == ans.size())
        ans = min(ans, a[i]);
    }
  }

  if (ans == "")
    return "None";

  return ans;
}