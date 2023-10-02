#include <iostream>

class Solution {
 public:
  static int sum(int num1, int num2) { return num1 + num2; }

  static void output(int num1, int num2) {
    std::cout << num1 << " + " << num2 << " = " << sum(num1, num2) << '\n';
  }
};

int main() {
  Solution::output(2, 3);
  Solution::output(-2, -8);
  Solution::output(0, 0);
  return 0;
}