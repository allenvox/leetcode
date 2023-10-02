#include <iostream>
#include <stack>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> parentheses;
    for (char c : s) {
      if (parentheses.empty() || c == '(' || c == '{' || c == '[') {
        parentheses.push(c);
      } else {
        if ((c == ')' && parentheses.top() != '(') ||
            (c == ']' && parentheses.top() != '[') ||
            (c == '}' && parentheses.top() != '{'))
          return false;
        else
          parentheses.pop();
      }
    }
    return parentheses.empty();
  }

  void output(string s) {
    cout << "Parentheses in string \"" << s << "\" are ";
    if (!isValid(s)) cout << "not ";
    cout << "valid" << endl;
  }
};

int main() {
  Solution s;
  s.output("{(([]))}");
  s.output("((((())))");
  s.output("([)]{}");
  s.output("{{[[[[{{}}]]]]}}}");
  s.output("[{([{()}])}]");
  return 0;
}