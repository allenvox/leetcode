#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> ans((unsigned long)n + 1, 0);
    for (unsigned long i = 1; i < ans.size(); i++)
      ans[i] = (int)i % 2 + ans[i / 2];
    return ans;
  }

  void output(int n) {
    vector<int> ans = countBits(n);
    cout << "Number of bits in all numbers before " << n << " = { ";
    for (unsigned long i = 0; i < (unsigned long)n; i++)
      cout << i << ":" << ans[i] << " ";
    cout << "}" << endl;
  }
};

int main() {
  cout << "Answer is outputted in format \"number:number_of_bits\"" << endl;
  Solution s;
  s.output(5);
  s.output(13);
  return 0;
}