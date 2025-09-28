// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Explanation:

// There is no string in strs that can be rearranged to form "bat".
// The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

// Example 2:

// Input: strs = [""]

// Output: [[""]]

// Example 3:

// Input: strs = ["a"]

// Output: [["a"]]

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Map {
    char* key;
    int* indices;
    int size;
} Map;

int compare(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Map* map = calloc(strsSize, sizeof(Map));
    char*** answer = malloc(sizeof(char*) * strsSize);
    *returnColumnSizes = malloc(sizeof(int) * strsSize);
    int mapSize = 0;
    
    for (int i = 0; i < strsSize; i++) {
        char* sortedKey = strdup(strs[i]);
        if (!sortedKey) continue;
        qsort(sortedKey, strlen(sortedKey), sizeof(char), compare);

        int found = 0;

        for (int j = 0; j < mapSize; j++) {
            if (strcmp(sortedKey, map[j].key) == 0) {
                map[j].indices[map[j].size++] = i;
                found = 1;
                break;
            }
        }

        if (! found) {
            map[mapSize].key = sortedKey;
            map[mapSize].indices = malloc(sizeof(int) * strsSize);
            map[mapSize].indices[0] = i;
            map[mapSize].size = 1;
            mapSize++;
        } else {
            free(sortedKey);
        }
    }

    *returnSize = mapSize;
    for (int i = 0; i < mapSize; i++) {
        (*returnColumnSizes)[i] = map[i].size;
        answer[i] = malloc(sizeof(char*) * map[i].size);

        for (int j = 0; j < map[i].size; j++) {
            int idx = map[i].indices[j];
            answer[i][j] = strdup(strs[idx]);
        }

        free(map[i].key);
        free(map[i].indices);
    }

    free(map);

    return answer;
}

int main() {
    // g.
    char* strs[] = {"eat","tea","tan","ate","nat","bat"};
    int strsSize = 6;
    int returnSize = 0;
    int* returnColumnSizes = NULL;

    char*** answer = groupAnagrams(strs, strsSize, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s ", answer[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < (*(returnColumnSizes + i)); j++) {
            free(answer[i][j]);
        }
        free(answer[i]);
    }
    free(answer);
    free(returnColumnSizes);

    return 0;
}

/**
 * Runtime: 947ms 13.38%
 * Memory: 175.24MB 23.46%
 */

// Group Anagrams