#include <stdio.h>

int xorOperation(int n, int start) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        res = res ^ (start + 2 * i);
    }
    return res;
}

void output(int n, int start) {
    printf("n = %d, start = %d: ( %d ", n, start, start);
    for(int i = 1; i < n; i++) {
        printf("XOR %d ", start + 2 * i);
    }
    printf(") = %d\n", xorOperation(n, start));
}

int main() {
    output(5, 0);
    output(4, 3);
    return 0;
}