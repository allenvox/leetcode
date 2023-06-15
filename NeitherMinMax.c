#include <stdio.h>

int findNonMinOrMax(int *nums, int numsSize) {
    int min = 101, max = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] > max) {
            max = nums[i];
        }
        if(nums[i] < min) {
            min = nums[i];
        }
    }
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != min && nums[i] != max) return nums[i];
    }
    return -1;
}

void output(int *nums, int numsSize) {
    printf("In array { ");
    for(int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("} non min or max ");
    int res = findNonMinOrMax(nums, numsSize);
    if(res != -1) {
        printf("is %d", res);
    } else {
        printf("doesn't exist");
    }
    printf("\n");
}

int main() {
    int nums1[3] = {2, 1, 3};
    output(nums1, 3);
    int nums2[4] = {3, 2, 1, 4};
    output(nums2, 4);
    int nums3[2] = {1, 2};
    output(nums3, 2);
    return 0;
}