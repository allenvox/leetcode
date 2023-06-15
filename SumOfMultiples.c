#include <stdio.h>

int sumOfMultiples(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0) sum += i;
    }
    return sum;
}

void output(int n) {
    printf("Sum of numbers divisible by {3; 5; 7} in range [1; %d] = %d\n", n, sumOfMultiples(n));
}

int main() {
    output(7);
    output(10);
    output(20);
    return 0;
}