// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Example 3:

// Input: nums = [1], target = 0
// Output: -1

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104

#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int li = 0;
    int ri = numsSize - 1;

    while (li <= ri) {
        int ci = (li + ri) / 2;
        int cv = nums[ci];
        int lv = nums[li];
        int rv = nums[ri];

        if (cv == target) return ci;
        if (lv == target) return li;
        if (rv == target) return ri;

        if (cv < rv) {
            if (cv < target && target < rv) li = ci + 1;
            else ri = ci - 1;
        } else {
            if (lv < target && target < cv) ri = ci - 1;
            else li = ci + 1;
        }
    }
    
    return -1;
}

int main() {
    // g.
    int nums[] = {4,5,6,7,0,1,2};
    int numsSize = 7;
    int target = 0;

    int answer = search(nums, numsSize, target);

    printf("answer: %d\n", answer);

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 8.39MB 60.78%
 */