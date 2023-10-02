#include <stdio.h>

int subtractProductAndSum(int n) {
  int product = 1, sum = 0;
  for (int i = 0; n > 0; i++) {
    int curdigit = n % 10;
    product *= curdigit;
    sum += curdigit;
    n /= 10;
  }
  return product - sum;
}

void output(int n) {
  printf("%d: (product of digits) - (sum of digits) = %d\n", n,
         subtractProductAndSum(n));
}

int main() {
  output(234);
  output(4421);
  return 0;
}