#include <iostream>
#include <queue>
using namespace std;

class Solution {
 public:
  string predictPartyVictory(string senate) {
    queue<unsigned long> rad, dir;
    unsigned long n = senate.size();
    for (unsigned long i = 0; i < n; i++) {
      if (senate[i] == 'R')
        rad.push(i);
      else
        dir.push(i);
    }
    while (!rad.empty() && !dir.empty()) {
      if (rad.front() < dir.front())
        rad.push(n++);
      else
        dir.push(n++);
      rad.pop();
      dir.pop();
    }
    return rad.empty() ? "Dire" : "Radiant";
  }

  void output(string senate) {
    cout << "The winner of Dota2 senate \"" << senate << "\" is "
         << predictPartyVictory(senate) << " party" << endl;
  }
};

int main() {
  Solution s;
  s.output("RD");
  s.output("RDD");
  s.output("RDDDRDRDRDDRRR");
  s.output("RRRDDDDR");
  return 0;
}