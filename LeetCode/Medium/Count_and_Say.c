// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the run-length encoding of countAndSay(n - 1).
// Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

// Given a positive integer n, return the nth element of the count-and-say sequence.

// Example 1:

// Input: n = 4

// Output: "1211"

// Explanation:

// countAndSay(1) = "1"
// countAndSay(2) = RLE of "1" = "11"
// countAndSay(3) = RLE of "11" = "21"
// countAndSay(4) = RLE of "21" = "1211"

// Example 2:

// Input: n = 1

// Output: "1"

// Explanation:

// This is the base case.

// Constraints:

// 1 <= n <= 30

#include <stdio.h>
#include <stdlib.h>

char* countAndSay(int n) {
    char* answer = malloc(5000);
    char* temp = malloc(5000);
    char* swapPtr;
    
    answer[0] = '1';
    answer[1] = '\0';

    for (int i = 1; i < n; i++) {
        int answerLoopIdx = 0;
        int tempWirteIdx = 0;
        int startIdx = 0;
        char digit = answer[0];

        while (answer[answerLoopIdx] != '\0') {
            if (answer[answerLoopIdx] != digit) {
                int count = answerLoopIdx - startIdx;
                temp[tempWirteIdx] = count + '0';
                temp[tempWirteIdx + 1] = digit;
                tempWirteIdx += 2;

                startIdx = answerLoopIdx;
                digit = answer[answerLoopIdx];
            } 
            
            answerLoopIdx++;
        }
        
        int count = answerLoopIdx - startIdx;
        temp[tempWirteIdx] = count + '0';
        temp[tempWirteIdx + 1] = digit;
        tempWirteIdx += 2;

        temp[tempWirteIdx] = '\0';
        
        swapPtr = answer;
        answer = temp;
        temp = swapPtr;
    }

    free(temp);
    return answer;
}

int main() {
    // g.
    int n = 4;  // 1211

    char* answer = countAndSay(n);
    printf("answer: %s\n", answer);

    free(answer);

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 8.58MB 71.46%
 */