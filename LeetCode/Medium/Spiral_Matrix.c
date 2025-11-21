// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:

// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = 0;
    int totalIndexNum = matrixSize * matrixColSize[0];
    int* answer = malloc(sizeof(int) * totalIndexNum);

    int offset = 0;
    while (*returnSize < totalIndexNum) {
        int top = offset;
        int bottom = matrixSize - offset - 1;
        int left = offset;
        int right = matrixColSize[top] - offset - 1;

        for (int c = left; c <= right; c++) {
            if ((*returnSize) >= totalIndexNum) break;
            answer[(*returnSize)++] = matrix[top][c];
        }

        for (int r = top + 1; r <= bottom; r++) {
            if ((*returnSize) >= totalIndexNum) break;
            answer[(*returnSize)++] = matrix[r][right];
        }

        for (int c = right - 1; c >= left; c--) {
            if ((*returnSize) >= totalIndexNum) break;
            answer[(*returnSize)++] = matrix[bottom][c];
        }

        for (int r = bottom - 1; r >= top + 1; r--) {
            if ((*returnSize) >= totalIndexNum) break;
            answer[(*returnSize)++] = matrix[r][left];
        }

        offset++;
    }

    return answer;
}

int main() {
    int matrixSize = 3;

    int _matrixColsize = 4;
    int* matrixColSize = malloc(sizeof(int) * _matrixColsize);
    for (int i = 0; i < matrixSize; i++) {
        matrixColSize[i] = _matrixColsize;
    }

    int _matrix[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
    };
    int** matrix = malloc(sizeof(int*) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        matrix[i] = malloc(sizeof(int) * matrixColSize[i]);

        for (int j = 0; j < matrixColSize[i]; j++) {
            matrix[i][j] = _matrix[i][j];
        }
    }

    int returnSize = 0;

    int* answer = spiralOrder(matrix, matrixSize, matrixColSize, &returnSize);
    printf("answer: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");
    
    free(answer);
    for (int i = 0; i < matrixSize; i++) free(matrix[i]);
    free(matrix);
    free(matrixColSize);

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 8.26MB 92.23%
 */