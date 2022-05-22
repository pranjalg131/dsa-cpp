#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
  stack<int> input, output;

public:
  MyQueue() {}

  void push(int x) { input.push(x); }

  int pop() {
    if (!output.empty()) {
      int x = output.top();
      output.pop();
      return x;
    } else {
      while (!input.empty()) {
        int x = input.top();
        output.push(x);
        input.pop();
      }

      int x = output.top();
      output.pop();
      return x;
    }
  }

  int peek() {
    if (!output.empty()) {
      int x = output.top();
      return x;
    } else {
      while (!input.empty()) {
        int x = input.top();
        output.push(x);
        input.pop();
      }

      int x = output.top();
      return x;
    }
  }

  bool empty() {
    while (!input.empty()) {
      int x = input.top();
      input.pop();
      output.push(x);
    }

    return output.empty();
  }
};