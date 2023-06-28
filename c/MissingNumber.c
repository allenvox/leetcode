#include <stdio.h>

int missingNumber(int *nums, int numsSize) {
    int sum = 0, total = numsSize * (numsSize + 1) / 2;
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    return total - sum;
}

void output(int *nums, int numsSize) {
    printf("Missing number in array { ");
    for(int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("} is %d\n", missingNumber(nums, numsSize));
}

int main() {
    int n1[] = {3, 0, 1};
    output(n1, 3);
    int n2[] = {0, 1};
    output(n2, 2);
    int n3[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    output(n3, 9);
    return 0;
}