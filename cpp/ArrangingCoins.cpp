#include <iostream>
using namespace std;

class Solution {
 public:
  int arrangeCoins(int n) {
    int i = 0;
    for (; n >= 0; n -= ++i)
      ;
    return i - 1;
  }

  void output(int n) {
    cout << "Using " << n << " coins you can build a staircase with "
         << arrangeCoins(n) << " complete stairs" << endl;
  }
};

int main() {
  Solution s;
  s.output(0);
  s.output(1);
  s.output(6);
  s.output(9);
  s.output(121);
  s.output(19);
  s.output(43);
  return 0;
}