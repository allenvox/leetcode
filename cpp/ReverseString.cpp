#include <iostream>
#include <vector>
using namespace std;

class Solution {
 private:
  void outCharVec(vector<char>& s) {
    for (char c : s) cout << c;
  }

 public:
  void reverseString(vector<char>& s) {
    s = vector<char>{s.rbegin(), s.rend()};
  }

  void output(vector<char>& s) {
    cout << "\"";
    outCharVec(s);
    cout << "\" after reverse will be \"";
    reverseString(s);
    outCharVec(s);
    cout << "\"" << endl;
  }
};

int main() {
  Solution s;
  vector<char> s1{'h', 'e', 'l', 'l', 'o'};
  s.output(s1);
  vector<char> s2{'H', 'a', 'n', 'n', 'a', 'h'};
  s.output(s2);
  return 0;
}