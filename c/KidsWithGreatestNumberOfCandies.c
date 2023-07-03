#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool *kidsWithCandies(int *candies, int candiesSize, int extraCandies,
                      int *returnSize) {
  *returnSize = sizeof(bool) * candiesSize;
  bool *results = malloc(*returnSize);
  int max = 0;
  for (int i = 0; i < candiesSize; i++) {
    if (candies[i] > max) {
      max = candies[i];
    }
  }
  for (int i = 0; i < candiesSize; i++) {
    if (candies[i] + extraCandies >= max) {
      results[i] = true;
    } else {
      results[i] = false;
    }
  }
  return results;
}

void output(int *candies, int candiesSize, int extraCandies, int *returnSize) {
  bool *results =
      kidsWithCandies(candies, candiesSize, extraCandies, returnSize);
  printf("If you give %d extra candies to\n", extraCandies);
  for (int i = 0; i < candiesSize; i++) {
    printf("Kid %d (%d candies): they'll have %d candies, which is ", i + 1,
           candies[i], candies[i] + extraCandies);
    if (!results[i]) {
      printf("not ");
    }
    printf("the greatest among the kids.\n");
  }
}

int main() {
  int resultSize = 0;
  int c1[5] = {2, 3, 5, 1, 3};
  output(c1, 5, 3, &resultSize);
  printf("\n");
  int c2[5] = {4, 2, 1, 1, 3};
  output(c2, 5, 1, &resultSize);
  return 0;
}