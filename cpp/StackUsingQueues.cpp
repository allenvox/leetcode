#include <iostream>
#include <queue>
using namespace std;

class MyStack {
 private:
  queue<int> q;

 public:
  MyStack() { cout << "Created new stack" << endl; }

  void push(int x) {
    int size = q.size();
    q.push(x);
    while (size) {
      q.push(q.front());
      q.pop();
      size--;
    }
    cout << "Pushed " << x << " in stack" << endl;
  }

  int pop() {
    int top = q.front();
    q.pop();
    cout << "Popped " << top << " out of stack" << endl;
    return top;
  }

  int top() { return q.front(); }

  bool empty() { return q.empty(); }
};

int main() {
  MyStack *obj = new MyStack();
  obj->push(3);
  obj->push(5);
  cout << obj->top() << " is on top of the stack" << endl;
  obj->pop();
  cout << "Stack is ";
  if (!obj->empty()) cout << "not ";
  cout << "empty" << endl;
  cout << obj->top() << " is on top of the stack" << endl;
  obj->pop();
  cout << "Stack is ";
  if (!obj->empty()) cout << "not ";
  cout << "empty" << endl;
  delete obj;
  return 0;
}