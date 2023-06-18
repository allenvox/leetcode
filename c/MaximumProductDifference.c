#include <stdio.h>

int maxProductDifference(int *nums, int numsSize) {
    int max1 = 0, max2 = 0, min1 = 10001, min2 = 10001;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] > max1) {
            max2 = max1;
            max1 = nums[i];
        } else if(nums[i] > max2) {
            max2 = nums[i];
        }
        if(nums[i] < min1) {
            min2 = min1;
            min1 = nums[i];
        } else if(nums[i] < min2) {
            min2 = nums[i];
        }
    }
    return (max1 * max2) - (min1 * min2);
}

void output(int *nums, int numsSize) {
    printf("Maximum product difference between two pairs from array { ");
    for(int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("} equals to %d\n", maxProductDifference(nums, numsSize));
}

int main() {
    int n1[] = {5, 6, 2, 7, 4};
    output(n1, 5);
    int n2[] = {4, 2, 5, 9, 7, 4, 8};
    output(n2, 7);
    return 0;
}