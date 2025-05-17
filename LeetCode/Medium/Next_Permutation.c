// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]

// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]

// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100

#include <stdio.h>

void nextPermutation(int* nums, int numsSize) {
    int idx = 0;
    int flag = 0;

    for (int i = numsSize - 1; i > 0; i--) {
        if (nums[i - 1] < nums[i]) {
            idx = i - 1;
            flag = 1;
            break;
        }
    }

    int idx2 = numsSize - 1;

    for (int i = idx + 1; i < numsSize; i++) {
        if (nums[idx] >= nums[i]) {
            idx2 = i - 1;
            break;
        }
    }

    int temp = nums[idx];
    nums[idx] = nums[idx2];
    nums[idx2] = temp;

    int left = flag == 0 ? 0 : idx + 1;
    int right = numsSize - 1;

    while (left < right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;

        left++;
        right--;
    }
}

int main() {
    // g.
    int nums[] = {3, 2, 5, 4, 1};   // 3 4 1 2 5
    int numsSize = 5;

    nextPermutation(nums, numsSize);

    printf("answer:");
    for (int i = 0; i < numsSize; i++) {
        printf(" %d", nums[i]);
    }
    printf("\n");

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 10.85MB 31.00%
 */
