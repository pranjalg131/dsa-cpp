#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
  queue<int> Q;

public:
  MyStack() {}

  void push(int x) {
    Q.push(x);
    int size = Q.size();
    for (int i = 0; i < size - 1; i++) {
      int x = Q.front();
      Q.pop();
      Q.push(x);
    }
  }

  int pop() {
    int x = Q.front();
    Q.pop();
    return x;
  }

  int top() { return Q.front(); }

  bool empty() { return Q.empty(); }
};