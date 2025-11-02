// Given a collection of candidate numbers (candidates) and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

void backtrack(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int start, int* path, int pathLen, int** answer) {
    if (target < 0) return;

    if (target == 0) {
        answer[*returnSize] = malloc(pathLen * sizeof(int));
        for (int i = 0; i < pathLen; i++) {
            answer[*returnSize][i] = path[i];
        }
        ((*returnColumnSizes)[*returnSize]) = pathLen;
        (*returnSize)++;
        return;
    } 

    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue;
        path[pathLen] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], returnSize, returnColumnSizes, i + 1, path, pathLen + 1, answer);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), compare);

    int** answer = malloc(150 * sizeof(int*));
    *returnColumnSizes = calloc(150, sizeof(int));

    int* path = malloc(candidatesSize * sizeof(int));
    *returnSize = 0;

    backtrack(candidates, candidatesSize, target, returnSize, returnColumnSizes, 0, path, 0, answer);

    free(path);

    answer = realloc(answer, (*returnSize) * sizeof(int*));
    *returnColumnSizes = realloc(*returnColumnSizes, (*returnSize) * sizeof(int));

    return answer;
}

int main() {
    // g.
    // int candidates[] = {10,1,2,7,6,1,5};
    int candidates[] = {2,1,5,3,5,4,1,3,2};
    // int candidatesSize = 7;
    int candidatesSize = 9;
    // int target = 8;
    int target = 10;
    int returnSize;
    int* returnColumnSizes = NULL;

    int** answer = combinationSum2(candidates, candidatesSize, target, &returnSize, &returnColumnSizes);
    printf("answer:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", answer[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]\n");
    }

    for (int i = 0; i < returnSize; i++) {
        free(answer[i]);
    }
    free(answer);
    free(returnColumnSizes);
    
    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 11.28MB 74.69%
 */