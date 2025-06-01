// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

// Constraints:

// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105

#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) (a < b ? a : b)

int trap(int* height, int heightSize) {
    int* pLeftMax = malloc(sizeof(int) * heightSize);
    int* pRightMax = malloc(sizeof(int) * heightSize);

    int leftMaxValue = 0;
    int rightMaxValue = 0;
    
    for (int i = 0; i < heightSize; i++) {
        *(pLeftMax + i) = leftMaxValue;
        if (leftMaxValue < height[i]) leftMaxValue = height[i];
        
        *(pRightMax + heightSize - 1 - i) = rightMaxValue;
        if (rightMaxValue < height[heightSize - 1 - i]) rightMaxValue = height[heightSize - 1 - i];
    }

    int sum = 0;
    for (int i = 1; i < heightSize - 1; i++) {
        int min = MIN( (*(pLeftMax + i)), (*(pRightMax + i)) );
        if (min <= height[i]) min = 0;
        else min -= height[i];
        sum += min;
    }

    free(pLeftMax);
    free(pRightMax);

    return sum;
}

int main() {
    // g.
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int heightSize = 12;

    int answer = trap(height, heightSize);
    printf("answer: %d\n", answer);

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 10.50MB 6.88%
 */