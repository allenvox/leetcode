#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 private:
  void quickSort(int l, int r, vector<int>& nums) {
    if (l >= r) {
      return;
    }

    int pivotIdx = l + (r - l) / 2;
    int pivotVal = nums[size_t(pivotIdx)];
    int i = l - 1;
    int j = r + 1;

    // partition
    while (i < j) {
      do {  // increment for smaller elems idx
        i++;
      } while (nums[size_t(i)] < pivotVal);

      do {  // decrement for larger elems idx
        j--;
      } while (nums[size_t(j)] > pivotVal);

      if (i < j) {  // if i and j haven't crossed
        std::swap(nums[size_t(i)], nums[size_t(j)]);
      }
    }

    // recursion
    quickSort(l, j, nums);      // left subarray
    quickSort(j + 1, r, nums);  // right subarray
  }

 public:
  vector<int> sortArray(vector<int>& nums) {
    quickSort(0, nums.size() - 1, nums);
    return nums;
  }

  void output(vector<int>& nums) {
    cout << "Array: { ";
    for (auto n : nums) cout << n << ' ';
    cout << "}, sorted: { ";
    sortArray(nums);
    for (auto n : nums) cout << n << ' ';
    cout << "}\n";
  }
};

int main() {
  Solution s;
  vector<int> n1{8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
  s.output(n1);
  vector<int> n2{5, 2, 3, 1, 0, 0, 1};
  s.output(n2);
  return 0;
}
