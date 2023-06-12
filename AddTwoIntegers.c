#include <stdio.h>

int sum(int num1, int num2) {
    return num1 + num2;
}

void output(int num1, int num2) {
    printf("%d + %d = %d\n", num1, num2, sum(num1, num2));
}

int main() {
    output(12, 5);
    output(-10, 4);
    return 0;
}