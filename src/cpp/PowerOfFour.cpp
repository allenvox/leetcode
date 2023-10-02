#include <iostream>
using namespace std;

class Solution {
 public:
  bool isPowerOfFour(int n) {
    if (n == 1) return true;
    if (n == 0 || n % 4 != 0) return false;
    return isPowerOfFour(n / 4);
  }

  void output(int n) {
    cout << n << " is ";
    if (!isPowerOfFour(n)) cout << "not ";
    cout << "a power of 4" << endl;
  }
};

int main() {
  Solution s;
  s.output(1);
  s.output(2);
  s.output(16);
  s.output(6129412);
  s.output(1024);
  return 0;
}