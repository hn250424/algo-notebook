// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Example 2:

// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 20
// -1000 <= matrix[i][j] <= 1000

#include <stdio.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i + 1; j < matrixColSize[i]; j++) {
            int t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j <= (matrixColSize[i] / 2) - 1; j++) {
            int t = matrix[i][j];
            matrix[i][j] = matrix[i][matrixColSize[i] - 1 - j];
            matrix[i][matrixColSize[i] - 1 - j] = t;
        }
    }
}

int main() {
    // g.
    int _matrix[4][4] = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    int matrixSize = 4;
    int matrixColSize[4] = {4, 4, 4, 4};
    int* matrix[3];
    for (int i = 0; i < matrixSize; i++) {
        matrix[i] = _matrix[i];
    }

    rotate(matrix, matrixSize, matrixColSize);

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 10.42MB 12.79%
 */