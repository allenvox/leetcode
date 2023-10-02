#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    unordered_map<char, int> counter(0);
    for (char c : s) counter[c]++;
    for (unsigned long i = 0; i < s.size(); i++) {
      if (counter[s[i]] == 1) return i;
    }
    return -1;
  }

  void output(string s) {
    int res = firstUniqChar(s);
    cout << "First unique character in string \"" << s << "\" ";
    if (res != -1)
      cout << "is on index " << res << " (\'" << s[(unsigned long)res] << "\')";
    else
      cout << "doesn't exist";
    cout << endl;
  }
};

int main() {
  Solution s;
  s.output("leetcode");
  s.output("love leetcode");
  s.output("aabb");
  return 0;
}