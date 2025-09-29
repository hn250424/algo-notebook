// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

// Note that you don't need to modify intervals in-place. You can make a new array and return it.

// Example 1:

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]

// Example 2:

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]

// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 
// Constraints:

// 0 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 105
// intervals is sorted by starti in ascending order.
// newInterval.length == 2
// 0 <= start <= end <= 105

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int** answer = malloc((intervalsSize + 1) * sizeof(int*));
    int idx = 0;

    int nf = newInterval[0];
    int ns = newInterval[1];

    for (int i = 0; i < intervalsSize; i++) {
        int f = intervals[i][0];
        int s = intervals[i][1];

        if (s < nf) {
            answer[idx] = malloc(2 * sizeof(int));
            answer[idx][0] = f;
            answer[idx][1] = s;
            idx++;
        } else if (f > ns) {
            answer[idx] = malloc(2 * sizeof(int));
            answer[idx][0] = nf;
            answer[idx][1] = ns;
            idx++;

            for (int j = i; j < intervalsSize; j++) {
                answer[idx] = malloc(2 * sizeof(int));
                answer[idx][0] = intervals[j][0];
                answer[idx][1] = intervals[j][1];
                idx++;
            }
            nf = -1;
            break;
        } else {
            nf = f < nf ? f : nf;
            ns = s > ns ? s : ns;
        }
    }

    if (nf != -1) {
        answer[idx] = malloc(2 * sizeof(int));
        answer[idx][0] = nf;
        answer[idx][1] = ns;
        idx++;
    }

    *returnSize = idx;
    *returnColumnSizes = malloc(idx * sizeof(int));
    for (int i = 0; i < idx; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return answer;
}

int main() {
    // int intervalSize = 2;
    int intervalSize = 5;
    int intervalColSize = 2;
    int** intervals = malloc(intervalSize * sizeof(int*));
    for (int i = 0; i < intervalSize; i++) {
        intervals[i] = malloc(intervalColSize * sizeof(int));
    }
    // intervals[0][0] = 1;
    // intervals[0][1] = 3;
    // intervals[1][0] = 6;
    // intervals[1][1] = 9;
    intervals[0][0] = 1;
    intervals[0][1] = 2;
    intervals[1][0] = 3;
    intervals[1][1] = 5;
    intervals[2][0] = 6;
    intervals[2][1] = 7;
    intervals[3][0] = 8;
    intervals[3][1] = 10;
    intervals[4][0] = 12;
    intervals[4][1] = 16;
    // int newInterval[2] = {2, 5};
    int newInterval[2] = {4, 8};
    int newIntervalSize = 2;
    int returnSize;
    int* returnColSize;

    int** answer = insert(intervals, intervalSize, &intervalColSize, newInterval, newIntervalSize, &returnSize, &returnColSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColSize[i]; j++) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < returnSize; i++) {
        free(answer[i]);
    }
    free(answer);
    free(returnColSize);

    for (int i = 0; i < intervalSize; i++) {
        free(intervals[i]);
    }
    free(intervals);

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 14.00MB 20.94%
 */
