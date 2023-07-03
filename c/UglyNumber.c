#include <stdbool.h>
#include <stdio.h>

bool isUgly(int n) {
  if (n < 1)
    return false;
  else if (n == 1)
    return true;
  else if (n % 2 == 0)
    return isUgly(n / 2);
  else if (n % 3 == 0)
    return isUgly(n / 3);
  else if (n % 5 == 0)
    return isUgly(n / 5);
  else
    return false;
}

void output(int n) {
  printf("%d is ", n);
  if (!isUgly(n)) printf("not ");
  printf("an ugly number (all of its prime factors are ");
  if (!isUgly(n)) printf("not ");
  printf("limited to 2, 3, and 5)\n");
}

int main() {
  output(6);
  output(1);
  output(14);
  return 0;
}