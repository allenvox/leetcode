#include <iostream>
using namespace std;

class Solution {
 public:
  int countSegments(string s) {
    int count = 0;
    bool word = false;
    for (char c : s) {
      if (c != ' ') {
        if (!word) {
          word = true;
          count++;
        }
      } else if (word) {
        word = false;
      }
    }
    return count;
  }

  void output(string s) {
    int ans = countSegments(s);
    cout << "String \"" << s << "\" has " << countSegments(s) << " segment";
    if (ans != 1) cout << 's';
    cout << endl;
  }
};

int main() {
  Solution s;
  s.output("Hello, my name is John");
  s.output("Hello");
  s.output("");
  s.output("lol          kek");
  s.output("       ");
  s.output("Hi!   !!");
  return 0;
}