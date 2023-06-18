#include <stdio.h>

double myPow(double x, long n){
    if (n == 0) return 1;
    if (n < 0) {
        return 1.0 / myPow(x, -n);
    }
    if (n % 2 == 1) { 
        return x * myPow(x * x, (n - 1) / 2);
    }
    return myPow(x * x, n / 2);
}

void output(double x, long n) {
    printf("%f^%ld = %f\n", x, n, myPow(x, n));
}

int main() {
    output(2.5, 5);
    output(2.5, -5);
    output(0.001, -123);
    output(2, 10);
    return 0;
}