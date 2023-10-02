#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isOneBitCharacter(vector<int>& bits) {
    for (unsigned long i = 0; i < bits.size(); i++) {
      if (bits[i] && ++i == bits.size() - 1) return false;
    }
    return true;
  }

  void output(vector<int>& bits) {
    cout << "Last char in bit array { ";
    for (auto x : bits) cout << x << " ";
    cout << "} must";
    if (!isOneBitCharacter(bits)) cout << "n\'t";
    cout << " be a 1-bit char" << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{1, 0, 1, 1, 0};
  s.output(v1);
  vector<int> v2{1, 0, 0};
  s.output(v2);
  vector<int> v3{1, 1, 1, 0};
  s.output(v3);
  return 0;
}