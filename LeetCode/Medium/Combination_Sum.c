// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

// Example 3:

// Input: candidates = [2], target = 1
// Output: []

// Constraints:

// 1 <= candidates.length <= 30
// 2 <= candidates[i] <= 40
// All elements of candidates are distinct.
// 1 <= target <= 40

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int** answer, int* path, int pathIdx, int si) {
    for (int i = si; i < candidatesSize; i++) {
        int nt = target - candidates[i];
        if (nt < 0) continue;
        path[pathIdx] = candidates[i];
        
        if (nt == 0) {
            int* temp = malloc(sizeof(int) * (pathIdx + 1));
            memcpy(temp, path, sizeof(int) * (pathIdx + 1));
            answer[*returnSize] = temp;
            (*returnColumnSizes)[*returnSize] = pathIdx + 1;
            (*returnSize)++;
        } else if (nt > 0) {
            backtrack(candidates, candidatesSize, nt, returnSize, returnColumnSizes, answer, path, pathIdx + 1, i);
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** answer = malloc(sizeof(int*) * 150);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 150);
    int path[40];
    
    backtrack(candidates, candidatesSize, target, returnSize, returnColumnSizes, answer, path, 0, 0);

    answer = realloc(answer, sizeof(int*) * (*returnSize));
    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*returnSize));

    return answer;
}

int main() {
    // g.
    int candidates[] = {2, 3, 6, 7};
    int candidatesSize = 4;
    int target = 7;
    int returnSize;
    int* returnColumnSizes;

    int** answer = combinationSum(candidates, candidatesSize, target, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < returnSize; ++i) {
        free(answer[i]);
    }
    free(answer);
    free(returnColumnSizes);

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 12.15MB 75.92%
 */