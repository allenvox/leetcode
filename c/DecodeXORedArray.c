#include <stdio.h>
#include <stdlib.h>

int *decode(int *encoded, int encodedSize, int first, int *returnSize) {
    *returnSize = encodedSize + 1;
    int *arr = malloc(sizeof(int) * (*returnSize));
    arr[0] = first;
    for(int i = 0; i < encodedSize; i++) {
        arr[i + 1] = arr[i] ^ encoded[i];
    }
    return arr;
}

void output(int *encoded, int encodedSize, int first) {
    printf("XORed array { ");
    for(int i = 0; i < encodedSize; i++) {
        printf("%d ", encoded[i]);
    }
    printf("} with first = %d is decoded into array { ", first);
    int decodedSize, *decoded = decode(encoded, encodedSize, first, &decodedSize);
    for(int i = 0; i < decodedSize; i++) {
        printf("%d ", decoded[i]);
    }
    printf("}\n");
}

int main() {
    int n1[] = {1, 2, 3};
    output(n1, 3, 1);
    int n2[] = {6, 2, 7, 3};
    output(n2, 4, 4);
    return 0;
}