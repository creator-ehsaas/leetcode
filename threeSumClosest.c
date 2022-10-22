// 3Sum Closest

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int i, j, k, sum, min, diff;
    qsort(nums, numsSize, sizeof(int), cmp);
    min = nums[0] + nums[1] + nums[2];
    for (i = 0; i < numsSize - 2; i++) {
        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];
            diff = abs(sum - target);
            if (diff < abs(min - target)) {
                min = sum;
            }
            if (sum < target) {
                j++;
            } else if (sum > target) {
                k--;
            } else {
                return target;
            }
        }
    }
    return min;
}

