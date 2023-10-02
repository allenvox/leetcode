#include <iostream>
using namespace std;

class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n == 1) return true;
    if (n < 1 || n % 3 != 0) return false;
    return isPowerOfThree(n / 3);
  }

  void output(int n) {
    cout << n << " is ";
    if (!isPowerOfThree(n)) cout << "not ";
    cout << "a power of 3" << endl;
  }
};

int main() {
  Solution s;
  s.output(1);
  s.output(-3);
  s.output(9);
  s.output(9999);
  s.output(27);
  return 0;
}