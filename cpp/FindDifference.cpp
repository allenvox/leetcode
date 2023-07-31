#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  char findTheDifference(string s, string t) {
    vector<int> scount(26, 0), tcount(26, 0);
    for (unsigned long i = 0; i < s.size(); i++) {
      scount[(unsigned long)(s[i] - 'a')]++;
      tcount[(unsigned long)(t[i] - 'a')]++;
    }
    tcount[(unsigned long)(t[t.size() - 1] - 'a')]++;
    char ans = '\0';
    for (unsigned long i = 0; i < 26; i++) {
      if (scount[i] != tcount[i]) ans = 'a' + (char)i;
    }
    return ans;
  }

  void output(string s, string t) {
    cout << "Difference between \"" << s << "\" and \"" << t << "\""
         << " is \'" << findTheDifference(s, t) << "\'" << endl;
  }
};

int main() {
  Solution s;
  s.output("", "y");
  s.output("abcd", "abcde");
  s.output("aloha", "hamloa");
  return 0;
}