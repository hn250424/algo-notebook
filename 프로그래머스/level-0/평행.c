// 문제 설명
// 점 네 개의 좌표를 담은 이차원 배열  dots가 다음과 같이 매개변수로 주어집니다.

// [[x1, y1], [x2, y2], [x3, y3], [x4, y4]]
// 주어진 네 개의 점을 두 개씩 이었을 때, 두 직선이 평행이 되는 경우가 있으면 1을 없으면 0을 return 하도록 solution 함수를 완성해보세요.

// 제한사항
// dots의 길이 = 4
// dots의 원소는 [x, y] 형태이며 x, y는 정수입니다.
// 0 ≤ x, y ≤ 100
// 서로 다른 두개 이상의 점이 겹치는 경우는 없습니다.
// 두 직선이 겹치는 경우(일치하는 경우)에도 1을 return 해주세요.
// 임의의 두 점을 이은 직선이 x축 또는 y축과 평행한 경우는 주어지지 않습니다.

// 입출력 예
// dots	result
// [[1, 4], [9, 2], [3, 8], [11, 6]]	1
// [[3, 5], [4, 1], [2, 4], [5, 10]]	0

// 입출력 예 설명
// 입출력 예 #1
// 점 [1, 4], [3, 8]을 잇고 [9, 2], [11, 6]를 이으면 두 선분은 평행합니다.
// 입출력 예 #2
// 점을 어떻게 연결해도 평행하지 않습니다.
// ※ 공지 - 2022년 9월 30일 제한 사항 및 테스트 케이스가 수정되었습니다.
// ※ 공지 - 2022년 10월 27일 제한 사항 및 테스트 케이스가 수정되었습니다.
// ※ 공지 - 2023년 2월 14일 테스트 케이스가 수정되었습니다.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool isParallel(int* a, int* b, int* c, int* d) {
    return (a[1] - b[1]) * (c[0] - d[0]) == (a[0] - b[0]) * (c[1] - d[1]);
}

// dots_rows는 2차원 배열 dots의 행 길이, dots_cols는 2차원 배열 dots의 열 길이입니다.
int solution(int** dots, size_t dots_rows, size_t dots_cols) {
    int answer = 0;
    
    if (
        isParallel(dots[0], dots[1], dots[2], dots[3]) ||
        isParallel(dots[0], dots[2], dots[1], dots[3]) ||
        isParallel(dots[0], dots[3], dots[1], dots[2]) 
    ) {
        answer = 1;
    }

    return answer;
}

int main() {
    // int dots[4][2] = { {1, 4}, {9, 2}, {3, 8}, {11, 6} };
    int dots[4][2] = { {3, 5}, {4, 1}, {2, 4}, {5, 10} };
    size_t dots_rows = 4;
    size_t dots_cols = 2;

    int** formatted_dots = (int**)malloc(dots_rows * sizeof(int*));
    for (size_t i = 0; i < dots_rows; i++) {
        formatted_dots[i] = dots[i];
        // printf("{ %d, %d }\n", formatted_dots[i][0], formatted_dots[i][1]);
    }

    const int answer = solution(formatted_dots, dots_rows, dots_cols);
    printf("answer: %d\n", answer);

    return 0;
}