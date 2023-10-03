#include <iostream>

class Solution {
 public:
  static bool squareIsWhite(std::string coordinates) {
    short letter = coordinates[0] % 2;  // a, c, e, g - odd, other - even
    short num = coordinates[1] % 2;     // 1, 3, 5, 7 - odd, other - even
    return letter != num;               // if both odd or even - square is black
  }

  static void output(std::string coordinates) {
    std::cout << "Chess square with coordinates \"" << coordinates << "\" is ";
    if (Solution::squareIsWhite(coordinates))
      std::cout << "white";
    else
      std::cout << "black";
    std::cout << '\n';
  }
};

int main() {
  Solution::output("a1");
  Solution::output("h3");
  Solution::output("c7");
  return 0;
}