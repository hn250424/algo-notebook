// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1] 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* answer = malloc(*returnSize * sizeof(int));
    answer[0] = -1;
    answer[1] = -1;

    if (numsSize == 0) return answer;
    
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int m = left + (right - left) / 2;
        if (nums[m] >= target) right = m - 1;
        else left = m + 1;
    }
    if (left < numsSize && nums[left] == target) answer[0] = left;
    else return answer;

    right = numsSize - 1;
    while (left <= right) {
        int m = left + (right - left) / 2;
        if (nums[m] <= target) left = m + 1;
        else right = m - 1;
    }
    answer[1] = right;
    
    return answer;
}

int main() {
    // g.
    int nums[] = {5,7,7,8,8,10};
    int numsSize = 6;
    int target = 8;
    int returnSize = 2;

    int* answer = searchRange(nums, numsSize, target, &returnSize);
    printf("answer: %d %d\n", answer[0], answer[1]);
    free(answer);

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 9.92MB 12.42%
 */