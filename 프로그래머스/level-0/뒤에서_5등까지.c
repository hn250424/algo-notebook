// 문제 설명
// 정수로 이루어진 리스트 num_list가 주어집니다. num_list에서 가장 작은 5개의 수를 오름차순으로 담은 리스트를 return하도록 solution 함수를 완성해주세요.

// 제한사항
// 6 ≤ num_list의 길이 ≤ 30
// 1 ≤ num_list의 원소 ≤ 100

// 입출력 예

// num_list	                    result
// [12, 4, 15, 46, 38, 1, 14]	[1, 4, 12, 14, 15]

// 입출력 예 설명

// 입출력 예 #1
// [12, 4, 15, 46, 38, 1, 14]를 정렬하면 [1, 4, 12, 14, 15, 38, 46]이 되고, 앞에서 부터 5개를 고르면 [1, 4, 12, 14, 15]가 됩니다.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    for(int i = 0; i < num_list_len; i++){
        for(int j = i; j <num_list_len; j++){
            if(num_list[i] > num_list[j]){
                int temp = num_list[i];
                num_list[i] = num_list[j];
                num_list[j] = temp;
            }
        }
    }
    
    return num_list;
}