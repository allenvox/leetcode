#include <iostream>
using namespace std;

class Solution {
 public:
  int countAsterisks(string s) {
    int flag = 0, count = 0;
    for (char c : s) {
      if (c == '|') {
        flag = !flag;
      } else if (c == '*') {
        if (!flag) count++;
      }
    }
    return count;
  }

  void output(string s) {
    cout << "There are " << countAsterisks(s)
         << " asterisks outside vertical bars in string \"" << s << "\""
         << endl;
  }
};

int main() {
  Solution s;
  s.output("l|*e*et|c**o|*de|");
  s.output("yo|uar|e**|b|e***au|tifu|l");
  return 0;
}