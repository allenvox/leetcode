#include <stdio.h>

int sum(int n1, int n2) {
    int res = 0;
    for(int i = n1; i <= n2; i++) {
        res += i;
    }
    return res;
}

int pivotInteger(int n) {
    for(int i = 1; i <= n; i++) {
        if(sum(1, i) == sum(i, n)) return i;
    }
    return -1;
}

void output(int n) {
    printf("Pivot integer in array from 1 to %d ", n);
    int res = pivotInteger(n);
    if(res == -1) {
        printf("doesn't exist");
    } else {
        printf("is %d (sum from 1 to %d = sum from %d to %d)", res, res, res, n);
    }
    printf("\n");
}

int main() {
    output(8);
    output(1);
    output(4);
    return 0;
}