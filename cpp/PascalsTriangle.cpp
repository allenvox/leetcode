#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++)
      ans.push_back(vector<int>((unsigned long)i + 1, 1));
    for (unsigned long i = 2; i < (unsigned long)numRows; i++)
      for (unsigned long j = 1; j < ans[i].size() - 1; j++)
        ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
    return ans;
  }

  void output(int numRows) {
    cout << "Pascal's triangle with " << numRows
         << " rows looks like this:" << endl;
    vector<vector<int>> ans = generate(numRows);
    for (vector<int> row : ans) {
      for (int x : row) cout << x << "\t";
      cout << endl;
    }
    cout << endl;
  }
};

int main() {
  Solution s;
  s.output(2);
  s.output(4);
  s.output(7);
  s.output(11);
  return 0;
}