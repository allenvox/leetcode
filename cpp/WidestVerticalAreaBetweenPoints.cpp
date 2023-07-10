#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    int ans = 0;
    for (unsigned long i = 1; i < points.size(); i++)
      ans = max(ans, (points[i][0] - points[i - 1][0]));
    return ans;
  }

  void output(vector<vector<int>>& points) {
    cout << "In array of points { ";
    for (vector<int> p : points) {
      cout << "{" << p[0] << "," << p[1] << "} ";
    }
    cout << "} answer is " << maxWidthOfVerticalArea(points) << endl;
  }
};

int main() {
  cout << "Widest area between 2 points containing no points" << endl;
  Solution s;
  vector<vector<int>> p1{{8, 7}, {9, 9}, {7, 4}, {9, 7}};
  s.output(p1);
  vector<vector<int>> p2{{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};
  s.output(p2);
  return 0;
}