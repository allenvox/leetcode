#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
 public:
  string reverseVowels(string s) {
    unsigned long i = 0, j = s.size() - 1;
    while (i < j) {
      i = s.find_first_of("aeiouAEIOU", i);
      j = s.find_last_of("aeiouAEIOU", j);
      if (i < j) swap(s[i++], s[j--]);
    }
    return s;
  }

  void output(string s) {
    cout << "\"" << s << "\" after reversing vowels will be "
         << reverseVowels(s) << endl;
  }
};

int main() {
  Solution s;
  s.output("hello");
  s.output("leetcode");
  return 0;
}