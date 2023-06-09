#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int removeElement(vector<int> &nums, int val) {
    unsigned long idx = 0;
    for (unsigned long i = 0; i < nums.size(); i++) {
      if (nums[i] != val) nums[idx++] = nums[i];
    }
    return (int)idx;
  }

  void output(vector<int> &nums, int val) {
    cout << "Vector { ";
    for (int num : nums) {
      cout << num << " ";
    }
    cout << "} (size " << nums.size() << ") without elements that equal to "
         << val << " will be { ";
    int size = removeElement(nums, val);
    for (unsigned long i = 0; i < (unsigned long)size; i++) {
      cout << nums[i] << " ";
    }
    cout << "} (size " << size << ")" << endl;
  }
};

int main() {
  Solution solution;
  vector<int> n1{3, 2, 2, 3};
  solution.output(n1, 3);
  vector<int> n2{0, 1, 2, 2, 3, 0, 4, 2};
  solution.output(n2, 2);
  return 0;
}