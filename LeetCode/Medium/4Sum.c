// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    if (numsSize < 4) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** answer = malloc(sizeof(int*) * 200);
    *returnColumnSizes = malloc(sizeof(int) * 200);

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int left = j + 1;
            int right = numsSize - 1;
            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    answer[*returnSize] = malloc(sizeof(int) * 4);
                    answer[*returnSize][0] = nums[i];
                    answer[*returnSize][1] = nums[j];
                    answer[*returnSize][2] = nums[left];
                    answer[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    int lv = nums[left];
                    int rv = nums[right];
                    while (left < right && nums[left] == lv) left++;
                    while (left < right && nums[right] == rv) right--;
                }
            }
        }
    }

    answer = realloc(answer, sizeof(int*) * (*returnSize));
    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*returnSize));

    return answer;
}

int main() {
    // g.
    int nums[] = {1,0,-1,0,-2,2};
    int numsSize = 6;
    int target = 0;
    int returnSize;
    int* returnColumnsSize;

    int** answer = fourSum(nums, numsSize, target, &returnSize, &returnColumnsSize);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnsSize[i]; j++) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < returnSize; i++) {
        free(answer[i]);
    }
    free(answer);
    free(returnColumnsSize);

    return 0;
}

/**
 * Runtime: 19ms 71.90%
 * Memory: 12.25MB 57.76%
 */