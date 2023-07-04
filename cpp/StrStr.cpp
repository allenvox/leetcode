#include <iostream>
using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.size() > haystack.size()) return -1;
    for (unsigned long i = 0; i <= haystack.size() - needle.size(); i++) {
      unsigned long j = 0;
      while (j < needle.size()) {
        if (haystack[i + j] != needle[j]) break;
        j++;
      }
      if (j == needle.size()) return i;
    }
    return -1;
  }

  void output(string haystack, string needle) {
    cout << "First occurence of \"" << needle << "\" in \"" << haystack
         << "\" ";
    int res = strStr(haystack, needle);
    if (res == -1)
      cout << "doesn't exist";
    else
      cout << "is at index " << res;
    cout << endl;
  }
};

int main() {
  Solution s;
  s.output("sadbutsad", "sad");
  s.output("leetcode", "leeto");
  return 0;
}