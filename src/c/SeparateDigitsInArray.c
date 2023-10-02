#include <stdio.h>
#include <stdlib.h>

int *separateDigits(int *nums, int numsSize, int *returnSize) {
  int size = 0;
  for (int i = 0; i < numsSize; i++) {
    int n = nums[i];
    while (n != 0) {
      size++;
      n /= 10;
    }
  }
  int *res = malloc(sizeof(int) * (unsigned long)size);
  int cur = size - 1;
  for (int i = numsSize - 1; i >= 0; i--) {
    int n = nums[i];
    while (n != 0) {
      res[cur] = n % 10;
      n /= 10;
      cur--;
    }
  }
  *returnSize = size;
  return res;
}

void output(int *nums, int numsSize) {
  printf("Separated digits from array { ");
  for (int i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }
  printf("} are { ");
  int resSize;
  int *res = separateDigits(nums, numsSize, &resSize);
  for (int i = 0; i < resSize; i++) {
    printf("%d ", res[i]);
  }
  printf("}\n");
  free(res);
}

int main() {
  int n1[] = {13, 25, 83, 77};
  output(n1, 4);
  int n2[] = {7, 1, 3, 9};
  output(n2, 4);
  return 0;
}