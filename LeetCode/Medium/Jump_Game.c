// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 
// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 105

#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    if (numsSize == 1) return true;
    int distance = 1;

    for (int i = numsSize - 2; i >= 1; i--) {
        if (nums[i] >= distance) distance = 1;
        else distance++;
    }

    if (nums[0] >= distance) return true;
    else return false;
}

int main() {
    // g.
    int nums[] = {2,3,1,1,4};
    int numsSize = 5;

    bool answer = canJump(nums, numsSize);
    printf("answer: %d\n", answer);

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 10.48MB 92.74%
 */

// Jump Game