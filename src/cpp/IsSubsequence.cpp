#include <iostream>
using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    unsigned long i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
      if (s[i] == t[j]) {
        i++;
      }
      j++;
    }
    return i == s.size();
  }

  void output(string s, string t) {
    cout << "\"" << s << "\" is ";
    if (!isSubsequence(s, t)) cout << "not ";
    cout << "a subsequence of \"" << t << "\"" << endl;
  }
};

int main() {
  Solution s;
  s.output("ace", "abcdefg");
  s.output("code", "leetcode");
  s.output("hola", "aloha");
  return 0;
}