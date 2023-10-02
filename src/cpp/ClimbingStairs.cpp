#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    vector<int> stairs((unsigned long)n + 1, -1);
    stairs[0] = 1, stairs[1] = 1;
    for (unsigned long i = 2; i < (unsigned long)n + 1; i++) {
      stairs[i] = stairs[i - 1] + stairs[i - 2];
    }
    return stairs[(unsigned long)n];
  }

  void output(int n) {
    cout << "There are " << climbStairs(n) << " ways to climb a staircase with "
         << n << " stairs" << endl;
  }
};

int main() {
  cout << "(a person can climb only 1 or 2 stairs at a time)" << endl;
  Solution s;
  s.output(2);
  s.output(3);
  s.output(10);
  s.output(21);
  return 0;
}