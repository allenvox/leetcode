#include <iostream>
using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    short frequency[26] = {0};
    for (unsigned long i = 0; i < magazine.size(); i++) {
      frequency[(unsigned long)(magazine[i] - 'a')]++;
    }
    for (unsigned long i = 0; i < ransomNote.size(); i++) {
      frequency[(unsigned long)(ransomNote[i] - 'a')]--;
    }
    for (auto x : frequency) {
      if (x < 0) return false;
    }
    return true;
  }

  void output(string ransomNote, string magazine) {
    cout << "You can";
    if (!canConstruct(ransomNote, magazine)) cout << "'t";
    cout << " construct string \"" << ransomNote << "\" from letters of \""
         << magazine << "\"" << endl;
  }
};

int main() {
  Solution s;
  s.output("abc", "abcde");
  s.output("aa", "abb");
  s.output("code", "leetcod");
  s.output("kebab", "baobab");
  return 0;
}