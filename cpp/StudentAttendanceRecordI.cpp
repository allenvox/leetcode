#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
 public:
  bool checkRecord(string s) {
    short absent = 0, lateRow = 0, maxLateRow = 0;
    for (char c : s) {
      switch (c) {
        case 'A':
          absent++;
          lateRow = 0;
          break;
        case 'L':
          lateRow++;
          maxLateRow = max(lateRow, maxLateRow);
          break;
        default:
          lateRow = 0;
      }
    }
    return absent < 2 && maxLateRow < 3;
  }

  void output(string s) {
    cout << "Student with attendance record \"" << s << "\" is ";
    if (!checkRecord(s)) cout << "not ";
    cout << "eligible for an attendance award" << endl;
  }
};

int main() {
  cout << "The student is eligible for an attendance award if they meet both "
          "of the following criteria:\nThe student was absent ('A') for "
          "strictly fewer than 2 days total.\nThe student was never late ('L') "
          "for 3 or more consecutive days.\n\n";
  Solution s;
  s.output("PPALLP");
  s.output("LALL");
  s.output("PPALLL");
  return 0;
}