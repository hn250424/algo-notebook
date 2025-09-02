// Given two binary strings a and b, return their sum as a binary string.

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"

// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"
 
// Constraints:

// 1 <= a.length, b.length <= 104
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int idx_a = strlen(a) - 1;
    int idx_b = strlen(b) - 1;
    int len = idx_a >= idx_b ? idx_a + 3 : idx_b + 3;
    char* answer = malloc(len);
    answer[len - 1] = '\0';
    int idx = len - 2;
    int w = 0;

    while (idx >= 0) {
        int value_a = idx_a >= 0 ? a[idx_a] - '0' : 0;
        int value_b = idx_b >= 0 ? b[idx_b] - '0' : 0;

        int sum = value_a + value_b + w;
        w = sum / 2;
        answer[idx] = sum % 2 + '0';

        if (idx_a >= 0) idx_a--;
        if (idx_b >= 0) idx_b--;
        idx--;
    }

    if (answer[0] == '0') {
        char* temp = strdup(answer + 1);
        free(answer);
        answer = temp;
    }

    return answer;
}

int main() {
    // g.
    char* a = "1010";
    char* b = "1011";

    char* answer = addBinary(a, b);
    printf("answer: %s\n", answer);

    free(answer);
    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 8.08MB 66.94%
 */