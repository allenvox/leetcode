#include <iostream>
using namespace std;

class Solution {
 public:
  int fib(int n) {
    switch (n) {
      case 0:
        return 0;
      case 1:
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
  }

  void output(int n) {
    cout << "Fibonacci number #" << n << " = " << fib(n) << endl;
  }
};

int main() {
  Solution s;
  s.output(2);
  s.output(8);
  s.output(12);
  return 0;
}