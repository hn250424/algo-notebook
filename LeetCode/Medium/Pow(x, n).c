// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000

// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100

// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

// Constraints:

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// n is an integer.
// Either x is not zero or n > 0.
// -104 <= xn <= 104

#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n) {
    if (n == 0) return 1.0000;

    long long ln = n;
    if (ln < 0) {
        ln *= -1;
        x = 1 / x;
    }

    double answer = 1;
    while (ln > 0) {
        if (ln & 1) answer *= x;
        x *= x;
        ln >>= 1;
    }

    return answer;
}

int main() {
    // g.
    double x = 2.00000;
    int n = 10;

    double answer = myPow(x, n);
    printf("answer: %f\n", answer);
    
    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 8.06MB 39.29%
 */