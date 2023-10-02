#include <stdio.h>

int numIdenticalPairs(int *nums, int numsSize) {
  int result = 0;
  for (int j = 0; j < numsSize; j++) {
    for (int i = 0; i < numsSize; i++) {
      if (i >= j || nums[i] != nums[j]) continue;
      result += 1;
    }
  }
  return result;
}

void output(int *nums, int numsSize) {
  printf("In array { ");
  for (int i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }
  printf("} are %d good pairs\n", numIdenticalPairs(nums, numsSize));
}

int main() {
  int nums1[6] = {1, 2, 3, 1, 1, 3};
  output(nums1, 6);
  int nums2[4] = {1, 1, 1, 1};
  output(nums2, 4);
  int nums3[3] = {1, 2, 3};
  output(nums3, 3);
  return 0;
}