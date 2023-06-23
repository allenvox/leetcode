// science of the solution:
// https://stackoverflow.com/questions/41181004/bitwise-xor-operator-to-find-missing-unique-id

#include <stdio.h>

int singleNumber(int *nums, int numsSize) {
    int unique = 0;
    for(int i = 0; i < numsSize; i++) {
        unique = unique ^ nums[i];
    }
    return unique;
}

void output(int *nums, int numsSize) {
    printf("Unique number in the sequence { ");
    for(int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("} is %d\n", singleNumber(nums, numsSize));
}

int main() {
    int n1[] = {2, 2, 1};
    output(n1, 3);
    int n2[] = {4, 1, 2, 1, 2};
    output(n2, 5);
    int n3[] = {1};
    output(n3, 1);
    return 0;
}