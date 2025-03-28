// 문제 설명
// x축과 y축으로 이루어진 2차원 직교 좌표계에 중심이 원점인 서로 다른 크기의 원이 두 개 주어집니다. 반지름을 나타내는 두 정수 r1, r2가 매개변수로 주어질 때, 두 원 사이의 공간에 x좌표와 y좌표가 모두 정수인 점의 개수를 return하도록 solution 함수를 완성해주세요.
// ※ 각 원 위의 점도 포함하여 셉니다.

// 제한 사항
// 1 ≤ r1 < r2 ≤ 1,000,000

// 입출력 예
// r1	r2	result
// 2	3	20

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(int r1, int r2) {
    long long answer = 0;
    long long square_r2 = (long long)r2 * r2;
    long long square_r1 = (long long)r1 * r1;

    for (long long y = 1; y < r2; y++) {
        long long square_y = y * y;

        long long left = 0, right = r2, max_x;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (mid * mid + square_y <= square_r2) {
                max_x = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        answer += max_x;

        left = 0, right = max_x;
        long long min_x = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (mid * mid + square_y < square_r1) {
                min_x = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        answer -= min_x;
    }

    answer += r2 - r1 + 1;
    answer *= 4;

    return answer;
}

int main() {
    // given. result: 20.
    // int r1 = 2;
    // int r2 = 3;

    // given. result: 952.
    // int r1 = 10;
    // int r2 = 20;

    // given. result: 6281440.
    int r1 = 999999;
    int r2 = 1000000;

    long answer = solution(r1, r2);
    printf("answer: %d\n", answer);

    return 0;
}