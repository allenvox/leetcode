#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    vector<int> expected(heights);
    sort(expected.begin(), expected.end());
    int count = 0;
    for (unsigned long i = 0; i < heights.size(); i++)
      if (heights[i] != expected[i]) count++;
    return count;
  }

  void output(vector<int>& heights) {
    cout << "Heights array { ";
    for (int x : heights) cout << x << " ";
    cout << "} has " << heightChecker(heights)
         << " indices with not non-decreasing order" << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{1, 1, 4, 2, 1, 3};
  s.output(v1);
  vector<int> v2{1, 2, 3, 4, 5};
  s.output(v2);
  vector<int> v3{5, 1, 2, 3, 4};
  s.output(v3);
  return 0;
}