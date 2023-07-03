#include <stdbool.h>
#include <stdio.h>

bool isPowerOfTwo(int n) {
  if (n > 0 && (n & (n - 1)) == 0) return true;
  return false;
}

void output(int n) {
  printf("%d is ", n);
  if (!isPowerOfTwo(n)) printf("not ");
  printf("a power of 2\n");
}

int main() {
  output(1);
  output(256);
  output(7);
  return 0;
}