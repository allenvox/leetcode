#include <iostream>
using namespace std;

class Solution {
 public:
  string toHex(int num) {
    unsigned int newnum = (unsigned int)num;
    string ans, hexchars("0123456789abcdef");
    do {
      ans += hexchars[(unsigned long)(newnum % 16)];
      newnum /= 16;
    } while (newnum);
    return {ans.rbegin(), ans.rend()};
  }

  void output(int num) {
    cout << "Decimal " << num << " = " << toHex(num) << " hexadecimal" << endl;
  }
};

int main() {
  Solution s;
  s.output(26);
  s.output(0);
  s.output(2941);
  s.output(-5);
  return 0;
}