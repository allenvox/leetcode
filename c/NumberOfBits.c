#include <stdio.h>
#include <inttypes.h>

int hammingWeight(uint32_t n) {
    if(n == 0) return 0;
    int count = 0;
    while(n != 0) {
        if(n & 1) count++;
        n >>= 1;
    }
    return count;
}

void printbinary(unsigned a) {
    if (a > 1) printbinary(a / 2);
    printf("%d", a % 2);
}

void output(uint32_t n) {
    printf("Number %d (");
    printbinary(n);
    printf(") contains %d bits\n", n, hammingWeight(n));
}

int main() {
    output(0b00000000000000000000000000001011);
    output(0b00000000000000000000000010000000);
    output(0b11111111111111111111111111111101);
    return 0;
}