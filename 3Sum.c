/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **result = (int **)malloc(sizeof(int *) * 10000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int target = -nums[i];
        int p = i + 1, q = numsSize - 1;
        while (p < q) {
            if (nums[p] + nums[q] == target) {
                result[*returnSize] = (int *)malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[p];
                result[*returnSize][2] = nums[q];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                while (p < q && nums[p] == nums[p + 1]) p++;
                while (p < q && nums[q] == nums[q - 1]) q--;
                p++, q--;
            } else if (nums[p] + nums[q] < target) {
                p++;
            } else {
                q--;
            }
        }
    }
    return result;
}

