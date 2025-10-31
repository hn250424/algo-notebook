// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
// The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.

// Example 2:

// Input: x = 8
// Output: 2

// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 
// Constraints:

// 0 <= x <= 231 - 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mySqrt(int x) {
    int answer = 0;
    int min = 0;
    int max = x;

    while (min <= max) {
        int m = (min + max) / 2;
        long long sq_m = (long long)m * m;
        
        if (sq_m > x) {
            max = m - 1;
        } else if (sq_m < x) {
            answer = m;
            min = m + 1;
        } else {
            return m;
        }
    }

    return answer;
}

int main() {
    // g.
    int x = 2;
    // int x = 4;
    // int x = 8;

    int answer = mySqrt(x);
    printf("answer: %d\n", answer);

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 8.44MB 73.20%
 */
