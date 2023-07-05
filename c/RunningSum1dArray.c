#include <stdio.h>
#include <stdlib.h>

int *runningSum(int *nums, int numsSize, int *returnSize) {
  int *results = malloc(sizeof(int) * (unsigned long)numsSize);
  for (int i = 0; i < numsSize; i++) {
    int sum = 0;
    for (int j = 0; j <= i; j++) {
      sum += nums[j];
    }
    results[i] = sum;
  }
  *returnSize = numsSize;
  return results;
}

void output(int *nums, int numsSize) {
  int returnSize;
  int *results = runningSum(nums, numsSize, &returnSize);
  printf("Running sum for each element of the array { ");
  for (int i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }
  printf("}: { ");
  for (int i = 0; i < numsSize; i++) {
    printf("%d ", results[i]);
  }
  printf("}\n");
  free(results);
}

int main() {
  int n1[4] = {1, 2, 3, 4};
  output(n1, 4);
  int n2[5] = {1, 1, 1, 1, 1};
  output(n2, 5);
  int n3[5] = {3, 1, 2, 10, 1};
  output(n3, 5);
  return 0;
}