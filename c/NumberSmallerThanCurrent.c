#include <stdio.h>
#include <stdlib.h>

int *smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize) {
  int *results = malloc(sizeof(int) * numsSize);
  for (int i = 0; i < numsSize; i++) {
    int local = 0;
    for (int j = 0; j < numsSize; j++) {
      if (i != j && nums[i] > nums[j]) local++;
    }
    results[i] = local;
  }
  *returnSize = numsSize;
  return results;
}

void output(int *nums, int numsSize) {
  int returnSize;
  int *results = smallerNumbersThanCurrent(nums, numsSize, &returnSize);
  printf("Smaller numbers count for each element in the array { ");
  for (int i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }
  printf("}: { ");
  for (int i = 0; i < numsSize; i++) {
    printf("%d ", results[i]);
  }
  printf("}\n");
}

int main() {
  int n1[4] = {6, 5, 4, 8};
  output(n1, 4);
  int n2[4] = {7, 7, 7, 7};
  output(n2, 4);
  int n3[5] = {8, 1, 2, 2, 3};
  output(n3, 5);
  return 0;
}