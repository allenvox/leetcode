#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> counter;
    for (int x : nums) {
      if ((unsigned long)(++counter[x]) > nums.size() / 2) return x;
    }
    return 0;
  }

  void output(vector<int>& nums) {
    cout << "Majoriy element of array { ";
    for (int x : nums) cout << x << " ";
    cout << "} is " << majorityElement(nums) << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{3, 2, 3};
  s.output(v1);
  vector<int> v2{2, 2, 1, 1, 1, 2, 2};
  s.output(v2);
  return 0;
}