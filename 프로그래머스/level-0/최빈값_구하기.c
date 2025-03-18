// 문제 설명
// 최빈값은 주어진 값 중에서 가장 자주 나오는 값을 의미합니다. 정수 배열 array가 매개변수로 주어질 때, 최빈값을 return 하도록 solution 함수를 완성해보세요. 최빈값이 여러 개면 -1을 return 합니다.

// 제한사항
// 0 < array의 길이 < 100
// 0 ≤ array의 원소 < 1000

// 입출력 예
// array	result
// [1, 2, 3, 3, 3, 4]	3
// [1, 1, 2, 2]	-1
// [1]	1

// 입출력 예 설명

// 입출력 예 #1
// [1, 2, 3, 3, 3, 4]에서 1은 1개 2는 1개 3은 3개 4는 1개로 최빈값은 3입니다.

// 입출력 예 #2
// [1, 1, 2, 2]에서 1은 2개 2는 2개로 최빈값이 1, 2입니다. 최빈값이 여러 개이므로 -1을 return 합니다.

// 입출력 예 #3
// [1]에는 1만 있으므로 최빈값은 1입니다.

// ※ 공지 - 2022년 10월 17일 제한 사항 및 테스트케이스가 수정되었습니다.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
	int i, j;
	
    int** countArray = (int**)malloc(array_len * sizeof(int*));
	for(int i = 0; i < array_len; i++) {
        countArray[i][0] = -1;
        countArray[i][1] = -1;
    }
	
	for(int i = 0; i < array_len; i++){
		int current_value = array[i];
		bool found = false;
		
		for(int j = 0; j < array_len; j++){
			if(current_value == countArray[j][0]){
				countArray[j][1]++;
				found = true;
				break;
			}
		}
		
		if(!found){
			for(int j = 0; j < array_len; j++){
				if(countArray[j][0] == -1){
					countArray[j][0] = current_value;
					countArray[j][1] = 1;
					break;
				}
			}
		}
	}
	
    int answer = 0;
    int maxValue = 0;
    
    for(int i = 0; i < array_len; i++){
    	int isMax = countArray[i][1];
    	if(maxValue < isMax){
			maxValue = isMax;
			answer = countArray[i][0];
		}
	}
	
	int countMaxValue = 0;
	for(int i = 0; i < array_len; i++){
		if(maxValue == countArray[i][1]) countMaxValue++;
		if(countMaxValue > 1) return -1;
	}
	
	printf("%d", answer);
    return answer;
}