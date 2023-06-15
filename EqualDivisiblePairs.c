#include <stdio.h>

int countPairs(int *nums, int numsSize, int k) {
    int res = 0;
    for(int i = 0; i < numsSize; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] == nums[j] && (i * j) % k == 0) {
                res += 1;
            }
        }
    }
    return res;
}

void output(int *nums, int numsSize, int k) {
    printf("In array { ");
    for(int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("} there are %d pairs whose indexes are divisible by %d\n", countPairs(nums, numsSize, k), k);
}

int main() {
    int n1[] = {3, 1, 2, 2, 2, 1, 3};
    output(n1, 7, 2);
    int n2[] = {1, 2, 3, 4};
    output(n2, 4, 1);
    return 0;
}