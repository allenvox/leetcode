#include <iostream>
using namespace std;

class Solution {
 public:
  bool canWinNim(int n) { return n & 3; }

  void output(int n) {
    cout << "You can";
    if (!canWinNim(n)) cout << "'t";
    cout << " win Nim Game with " << n << " stones if you go first" << endl;
  }
};

int main() {
  Solution s;
  s.output(5);
  s.output(1);
  s.output(4);
  s.output(1248);
  return 0;
}