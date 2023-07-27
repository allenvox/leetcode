#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> s{"1"};
    for (int i = 2; i <= n; i++) {
      string ans = "";
      if (i % 3 == 0) ans += "Fizz";
      if (i % 5 == 0) ans += "Buzz";
      if (i % 3 && i % 5) ans += to_string(i);
      s.push_back(ans);
    }
    return s;
  }

  void output(int n) {
    cout << "For numbers from 1 to " << n << " FizzBuzz array will be { ";
    vector<string> s = fizzBuzz(n);
    for (string x : s) cout << x + " ";
    cout << "}" << endl;
  }
};

int main() {
  cout << "\"Fizz\" means that number is divisible by 3, \"Buzz\" - divisible "
          "by 5, \"FizzBuzz\" - divisible by 15 (3 and 5)"
       << endl;
  Solution s;
  s.output(5);
  s.output(16);
  return 0;
}