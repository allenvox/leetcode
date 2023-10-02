#include <iostream>
using namespace std;

class Solution {
 private:
  bool isCapital(char c) {
    if (c >= 'A' && c <= 'Z') return true;
    return false;
  }

 public:
  bool detectCapitalUse(string word) {
    int capcount = 0, lowcount = 0, firstcap = 0;
    if (isCapital(word[0]))
      firstcap++;
    else
      lowcount++;
    for (unsigned long i = 1; i < word.size(); i++) {
      if (isCapital(word[i]))
        capcount++;
      else
        lowcount++;
      if ((firstcap && capcount && lowcount) || (capcount && lowcount))
        return false;
    }
    return true;
  }

  void output(string s) {
    cout << "Usage of capitals in string \"" << s << "\" is ";
    if (!detectCapitalUse(s)) cout << "not ";
    cout << "right" << endl;
  }
};

int main() {
  Solution s;
  s.output("USA");
  s.output("leetcode");
  s.output("FlaG");
  s.output("mL");
  s.output("FFFf");
  return 0;
}