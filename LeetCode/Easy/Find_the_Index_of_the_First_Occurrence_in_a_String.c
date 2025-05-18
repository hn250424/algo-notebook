// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.

// Constraints:

// 1 <= haystack.length, needle.length <= 104
// haystack and needle consist of only lowercase English characters.

#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    for (int i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == needle[0]) {
            int idx = 0;

            while (1) {
                if (haystack[i + idx] == needle[idx]) {
                    if (needle[idx + 1] == '\0') return i;
                    else idx++;
                } else {
                    break;
                }
            }
        }
    }

    return -1;
}

int main() {
    // g.
    char haystack[] = "mississippi";
    char needle[] = "issip";

    int answer = strStr(haystack, needle);
    printf("answer: %d\n", answer);

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 8.02MB 29.33%
 */