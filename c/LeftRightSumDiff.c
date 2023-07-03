#include <stdio.h>
#include <stdlib.h>

int *leftRightDifference(int *nums, int numsSize, int *returnSize) {
  int *results = malloc(sizeof(int) * numsSize);
  for (int i = 0; i < numsSize; i++) {
    int leftsum = 0;
    for (int j = 0; j < i; j++) {
      leftsum += nums[j];
    }
    int rightsum = 0;
    for (int j = i + 1; j < numsSize; j++) {
      rightsum += nums[j];
    }
    int diff = leftsum - rightsum;
    if (diff < 0) diff *= -1;
    results[i] = diff;
  }
  *returnSize = numsSize;
  return results;
}

void output(int *nums, int numsSize) {
  int resultSize;
  int *results = leftRightDifference(nums, numsSize, &resultSize);
  printf("Difference between left and right sum:\n");
  for (int i = 0; i < numsSize; i++) {
    printf("%d: %d\n", nums[i], results[i]);
  }
}

int main() {
  int n1[4] = {10, 4, 8, 3};
  output(n1, 4);
  printf("\n");
  int n2[1] = {1};
  output(n2, 1);
  return 0;
}