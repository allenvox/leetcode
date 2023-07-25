#include <iostream>
using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    char seen[128] = {};
    for (unsigned long i = 0; i < s.size(); i++) {
      char c1 = s[i];
      if (!seen[(unsigned long)c1]) {
        for (char c2 : seen)
          if (c2 == t[i]) return false;
        seen[(unsigned long)c1] = t[i];
      } else if (seen[(unsigned long)c1] != t[i])
        return false;
    }
    return true;
  }

  void output(string s, string t) {
    cout << "Strings \"" << s << "\" and \"" << t << "\" are ";
    if (!isIsomorphic(s, t)) cout << "not ";
    cout << "isomorphic" << endl;
  }
};

int main() {
  cout << "Two strings s1 and s2 are isomorphic if the characters in s1 can be "
          "replaced by unique characters to get s2"
       << endl;
  Solution s;
  s.output("add", "egg");
  s.output("foo", "bar");
  s.output("paper", "title");
  return 0;
}