// 문제 설명
// 길이가 같은 배열 A, B 두개가 있습니다. 각 배열은 자연수로 이루어져 있습니다.
// 배열 A, B에서 각각 한 개의 숫자를 뽑아 두 수를 곱합니다. 이러한 과정을 배열의 길이만큼 반복하며, 두 수를 곱한 값을 누적하여 더합니다. 이때 최종적으로 누적된 값이 최소가 되도록 만드는 것이 목표입니다. (단, 각 배열에서 k번째 숫자를 뽑았다면 다음에 k번째 숫자는 다시 뽑을 수 없습니다.)

// 예를 들어 A = [1, 4, 2] , B = [5, 4, 4] 라면

// A에서 첫번째 숫자인 1, B에서 첫번째 숫자인 5를 뽑아 곱하여 더합니다. (누적된 값 : 0 + 5(1x5) = 5)
// A에서 두번째 숫자인 4, B에서 세번째 숫자인 4를 뽑아 곱하여 더합니다. (누적된 값 : 5 + 16(4x4) = 21)
// A에서 세번째 숫자인 2, B에서 두번째 숫자인 4를 뽑아 곱하여 더합니다. (누적된 값 : 21 + 8(2x4) = 29)
// 즉, 이 경우가 최소가 되므로 29를 return 합니다.

// 배열 A, B가 주어질 때 최종적으로 누적된 최솟값을 return 하는 solution 함수를 완성해 주세요.

// 제한사항
// 배열 A, B의 크기 : 1,000 이하의 자연수
// 배열 A, B의 원소의 크기 : 1,000 이하의 자연수

// 입출력 예
// A	B	answer
// [1, 4, 2]	[5, 4, 4]	29
// [1,2]	[3,4]	10

// 입출력 예 설명
// 입출력 예 #1
// 문제의 예시와 같습니다.

// 입출력 예 #2
// A에서 첫번째 숫자인 1, B에서 두번째 숫자인 4를 뽑아 곱하여 더합니다. (누적된 값 : 4) 다음, A에서 두번째 숫자인 2, B에서 첫번째 숫자인 3을 뽑아 곱하여 더합니다. (누적된 값 : 4 + 6 = 10)
// 이 경우가 최소이므로 10을 return 합니다.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare_asc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compare_desc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.
int solution(int A[], size_t A_len, int B[], size_t B_len) {
    qsort(A, A_len, sizeof(int), compare_asc);
    qsort(B, B_len, sizeof(int), compare_desc);

    int answer = 0;
    for (size_t i = 0; i < A_len; i++) {
        answer += A[i] * B[i];
    }

    return answer;
}

int main() {
    // given 1. answer = 29.
    int A[] = { 1, 4, 2 };
    int B[] = { 5, 4, 4 };
    size_t A_len = 3;
    size_t B_len = 3;

    // given 2. answer = 10.
    // int A[] = { 1, 2 };
    // int B[] = { 3, 4 };
    // size_t A_len = 2;
    // size_t B_len = 2;

    int answer = solution(A, A_len, B, B_len);
    printf("answer: %d\n", answer);

    return 0;
}