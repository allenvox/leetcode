#include <stdio.h>

int smallestEvenMultiple(int n) {
  if (n % 2 == 0) return n;
  return 2 * n;
}

void output(int n) {
  printf("Smallest multiple of both 2 and %d is %d\n", n,
         smallestEvenMultiple(n));
}

int main() {
  output(5);
  output(6);
  return 0;
}