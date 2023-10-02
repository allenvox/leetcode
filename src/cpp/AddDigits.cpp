#include <iostream>
using namespace std;

class Solution {
 public:
  int addDigits(int num) {
    if (num < 10) return num;
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return addDigits(sum);
  }

  void output(int num) {
    cout << "Recursive sum of digits of " << num << " results to "
         << addDigits(num) << endl;
  }
};

int main() {
  Solution s;
  s.output(38);
  s.output(1);
  s.output(123);
  return 0;
}