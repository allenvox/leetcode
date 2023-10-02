#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int diagonalSum(vector<vector<int>>& mat) {
    int ans = 0;
    for (unsigned long i = 0; i < mat.size(); i++) {
      ans += mat[i][i];
      ans += mat[i][mat.size() - 1 - i];
    }
    if (mat.size() % 2) ans -= mat[mat.size() / 2][mat.size() / 2];
    return ans;
  }

  void output(vector<vector<int>>& mat) {
    cout << "Matrix:" << endl;
    for (vector<int> row : mat) {
      for (int x : row) cout << x << " ";
      cout << endl;
    }
    cout << "Diagonal sum = " << diagonalSum(mat) << endl;
  }
};

int main() {
  Solution s;
  vector<vector<int>> m1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  s.output(m1);
  cout << endl;
  vector<vector<int>> m2{
      {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
  s.output(m2);
  cout << endl;
  vector<vector<int>> m3{{5}};
  s.output(m3);
  return 0;
}