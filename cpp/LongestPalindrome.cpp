#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int longestPalindrome(string s) {
    unsigned long oddCount = 0;
    unordered_map<char, int> umap;
    for (char c : s) {
      umap[c]++;
      if (umap[c] % 2 == 1)
        oddCount++;
      else
        oddCount--;
    }
    if (oddCount > 1) return s.size() - oddCount + 1;
    return s.size();
  }

  void output(string s) {
    cout << "The biggest palindrome from letters of \"" << s << "\" will be "
         << longestPalindrome(s) << " characters long" << endl;
  }
};

int main() {
  Solution s;
  s.output("abccccdd");
  s.output("a");
  s.output("");
  s.output("leetcode");
  s.output("racecar");
  return 0;
}