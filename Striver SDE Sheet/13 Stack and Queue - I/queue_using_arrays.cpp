#include <bits/stdc++.h>
using namespace std;

class myQueue {
private:
  vector<int> arr;
  int maxSize;
  int start;
  int end;
  int currSize;

public:
  myQueue() {
    maxSize = 1000;
    arr.resize(maxSize);
    start = end = -1;
    currSize = 0;
  }

  void enque(int x) {
    if (this->size() == 0) {
      start++;
      end++;
      arr[start] = x;
    } else {
      end++;
      arr[end] = x;
    }
  }

  void deque() {
    if (this->size() == 1) {
      start = end = -1;
    } else {
      start++;
    }
  }

  int front() { return arr[start]; }

  int size() {
    if (start == end && end == -1)
      return 0;
    else
      return (end - start + 1);
  }

  bool empty() { return (end == -1) && (start == end); }
};

int main() {
  myQueue Q;

  Q.enque(1);
  Q.enque(2);
  Q.enque(3);
  Q.enque(4);
  Q.enque(5);

  while (!Q.empty()) {
    cout << Q.front() << " ";
    Q.deque();
  }

  cout << Q.size() << endl;
  Q.enque(2);
  cout << Q.size() << endl;
  Q.deque();
  cout << Q.size() << endl;
}