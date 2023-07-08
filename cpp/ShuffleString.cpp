#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string restoreString(string s, vector<int> &indices) {
    string ans = s;
    unsigned long cur = 0;
    for (int i : indices) {
      ans[(unsigned long)i] = s[cur++];
    }
    return ans;
  }

  void output(string s, vector<int> &indices) {
    cout << "String \"" << s << "\" after shuffling with indices { ";
    for (int i : indices) {
      cout << i << " ";
    }
    cout << "} is string \"" << restoreString(s, indices) << "\"" << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{4, 5, 6, 7, 0, 2, 1, 3};
  s.output("codeleet", v1);
  vector<int> v2{0, 1, 2};
  s.output("abc", v2);
  return 0;
}