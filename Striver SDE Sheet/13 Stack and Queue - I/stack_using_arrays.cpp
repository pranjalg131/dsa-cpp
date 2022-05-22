#include <bits/stdc++.h>
using namespace std;

class myStack {
private:
  vector<int> arr;
  int curr;
  int max_size = 10000;

public:
  myStack() {
    arr.resize(max_size);
    curr = -1;
  }

  void push(int el) {
    curr++;
    if (curr < max_size)
      arr[curr] = el;
  }

  void pop() {
    if (curr >= 0)
      curr--;
  }

  int top() { return curr >= 0 ? arr[curr] : INT_MIN; }

  bool empty() { return curr == -1; }

  int size() { return curr + 1; }
};

int main() {
  myStack st;

  st.push(5);
  st.push(4);
  st.push(3);
  st.push(2);
  st.push(1);

  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }

  cout << st.size() << endl;
  st.push(5);
  cout << st.size() << endl;
  st.pop();
  cout << st.size() << endl;

  cout << endl;
}