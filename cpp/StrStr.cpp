#include <iostream>
using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.size() > haystack.size()) return -1;
    for (int i = 0; i <= (int)(haystack.size() - needle.size()); i++) {
      int j = 0;
      while (j < (int)needle.size()) {
        if (haystack[i + j] != needle[j]) break;
        j++;
      }
      if (j == (int)needle.size()) return i;
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