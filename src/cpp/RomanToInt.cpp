#include <iostream>

class Solution {
 public:
  static int decimalNum(char r) {
    switch (r) {
      case 'M':
        return 1000;
      case 'D':
        return 500;
      case 'C':
        return 100;
      case 'L':
        return 50;
      case 'X':
        return 10;
      case 'V':
        return 5;
      case 'I':
        return 1;
      default:
        return -1;
    }
  }

  static int romanToInt(std::string s) {
    int res = 0;
    std::size_t len = s.size();
    for (std::size_t i = 0; i < len; ++i) {
      if (decimalNum(s[i]) < decimalNum(s[i + 1]))
        res -= decimalNum(s[i]);
      else
        res += decimalNum(s[i]);
    }
    return res;
  }

  static void output(std::string s) {
    std::cout << "Roman number \"" << s << "\" = " << Solution::romanToInt(s)
              << " decimal\n";
  }
};

int main() {
  Solution::output("III");
  Solution::output("LVIII");
  Solution::output("MCMXCIV");
  return 0;
}