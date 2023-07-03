#include <stdio.h>

int largestAltitude(int *gain, int gainSize) {
  int max = 0, cur = 0;
  for (int i = 0; i < gainSize; i++) {
    cur += gain[i];
    if (cur > max) max = cur;
  }
  return max;
}

void output(int *gain, int gainSize) {
  printf(
      "Highest altitude of biker (starting from 0) according to net gain array "
      "{");
  for (int i = 0; i < gainSize; i++) {
    printf("%d ", gain[i]);
  }
  printf("} equals to %d\n", largestAltitude(gain, gainSize));
}

int main() {
  int g1[] = {-5, 1, 5, 0, -7};
  output(g1, 5);
  int g2[] = {-4, -3, -2, -1, 4, 3, 2};
  output(g2, 7);
  return 0;
}