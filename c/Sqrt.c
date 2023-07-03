#include <stdio.h>

int mySqrt(int x) {
  long int root = 0;
  while (root * root <= x) {
    root++;
  }
  return (int)root - 1;
}

void output(int x) {
  printf("Integer square root of %d equals to %d\n", x, mySqrt(x));
}

int main() {
  output(4);
  output(8);
  output(1);
  output(0);
  output(225);
  return 0;
}