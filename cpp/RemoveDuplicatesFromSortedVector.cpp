#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    unsigned long dupcount = 0;
    for (unsigned long i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1])
        dupcount++;
      else
        nums[i - dupcount] = nums[i];
    }
    return nums.size() - dupcount;
  }

  void output(vector<int> &nums) {
    cout << "Vector { ";
    for (int num : nums) {
      cout << num << " ";
    }
    cout << "} (size " << nums.size() << ") without duplicates will be { ";
    int size = removeDuplicates(nums);
    for (unsigned long i = 0; i < (unsigned long)size; i++) {
      cout << nums[i] << " ";
    }
    cout << "} (size " << size << ")" << endl;
  }
};

int main() {
  Solution solution;
  vector<int> n1{1, 1, 2};
  solution.output(n1);
  vector<int> n2{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  solution.output(n2);
  return 0;
}