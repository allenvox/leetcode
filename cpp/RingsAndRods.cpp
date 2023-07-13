#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int countPoints(string rings) {
    vector<vector<bool>> rods(10, vector<bool>(3, false));
    for (unsigned long i = 0; i < rings.size(); i += 2) {
      unsigned long rodnum = (unsigned long)(rings[i + 1] - '0'), color;
      if (rings[i] == 'R')
        color = 0;
      else if (rings[i] == 'G')
        color = 1;
      else
        color = 2;
      rods[rodnum][color] = true;
    }
    int count = 0;
    for (vector<bool> rod : rods) {
      if (rod[0] && rod[1] && rod[2]) count++;
    }
    return count;
  }

  void output(string rings) {
    int res = countPoints(rings);
    cout << "For rings & rods string \"" << rings << "\" there are ";
    if (!res)
      cout << "no";
    else
      cout << res;
    cout << " rods with rings all colors on it" << endl;
  }
};

int main() {
  Solution s;
  s.output("B0B6G0R6R0R6G9");
  s.output("G4");
  s.output("B0R0G0R9R0B0G0B9G9");
  return 0;
}