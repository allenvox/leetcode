#include <iostream>
using namespace std;

class Solution {
 private:
  int nextNum(int n) {
    int next = 0;
    while (n != 0) {
      int digit = n % 10;
      next += digit * digit;
      n /= 10;
    }
    return next;
  }

 public:
  bool isHappy(int n) {
    int oneStep = n, twoSteps = nextNum(n);
    while (twoSteps != 1 && twoSteps != oneStep) {
      oneStep = nextNum(oneStep);
      twoSteps = nextNum(nextNum(twoSteps));
    }
    return twoSteps == 1;
  }

  void output(int n) {
    cout << n << " is ";
    if (!isHappy(n)) cout << "not ";
    cout << "a happy number" << endl;
  }
};

int main() {
  cout << "A happy number is a number defined by the following "
          "process:\nStarting with any positive integer, replace the number by "
          "the sum of the squares of its digits.\nRepeat the process until the "
          "number equals 1 (where it will stay), or it loops endlessly in a "
          "cycle which does not include 1.\nThose numbers for which this "
          "process ends in 1 are happy.\n";
  Solution s;
  s.output(19);
  s.output(2);
  s.output(111);
  return 0;
}