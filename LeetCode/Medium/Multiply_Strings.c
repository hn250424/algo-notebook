// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"

// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088" 

// Constraints:

// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    int total_len = num1_len + num2_len;
    int* result = calloc(total_len + 1, sizeof(int));

    for (int i = 0; i < num1_len; i++) {
        int n1 = num1[num1_len - i - 1] - '0';

        for (int j = 0; j < num2_len ; j++) {
            int n2 = num2[num2_len - j - 1] - '0';
            
            int m = n1 * n2;

            int idx = total_len - 1 - i - j;
            int w = result[idx];

            int s = m + w;

            result[idx - 1] += s / 10;
            result[idx] = s % 10;
        }
    }

    int first_nonzero = 0;
    while (first_nonzero < total_len - 1 && result[first_nonzero] == 0) {
        first_nonzero++;
    }

    int result2_len = total_len - first_nonzero;
    char* result2 = malloc(result2_len + 1);
    
    for (int i = 0; i < result2_len; i++) {
        result2[i] = result[first_nonzero + i] + '0';
    }
    result2[result2_len] = '\0';

    free(result);
    return result2;
}

int main() {
    char* num1 = "123";
    char* num2 = "456";
    // char* num1 = "12";
    // char* num2 = "4";
    // char* num1 = "12";
    // char* num2 = "10";
    char* answer = multiply(num1, num2);
    printf("%s\n", answer);
    free(answer);

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 8.23MB 42.86%
 */
