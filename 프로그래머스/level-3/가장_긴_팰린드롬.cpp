// 문제 설명
// 앞뒤를 뒤집어도 똑같은 문자열을 팰린드롬(palindrome)이라고 합니다.
// 문자열 s가 주어질 때, s의 부분문자열(Substring)중 가장 긴 팰린드롬의 길이를 return 하는 solution 함수를 완성해 주세요.

// 예를들면, 문자열 s가 "abcdcba"이면 7을 return하고 "abacde"이면 3을 return합니다.

// 제한사항
// 문자열 s의 길이 : 2,500 이하의 자연수
// 문자열 s는 알파벳 소문자로만 구성

// 입출력 예
// s	        answer
// "abcdcba"	7
// "abacde"	    3

// 입출력 예 설명
// 입출력 예 #1
// 4번째자리 'd'를 기준으로 문자열 s 전체가 팰린드롬이 되므로 7을 return합니다.

// 입출력 예 #2
// 2번째자리 'b'를 기준으로 "aba"가 팰린드롬이 되므로 3을 return합니다.

// ※ 공지 - 2023년 8월 21일 테스트케이스가 추가되었습니다. 기존에 제출한 코드가 통과하지 못할 수도 있습니다.

#include <string>

#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    const int s_size = s.size();
    int answer = 0;

    if (s_size < 2) return s_size;    
    else if (s_size == 2 && s[0] != s[1]) return 1;
    else if (s_size == 2 && s[0] == s[1]) return 2;

    for (int i = 0; i < s_size - 1; i++) {
        int w = 0;

        for (int j = i + 1; j < s_size; j++) {
            if (s[i] == s[j]) w = j - i;
            else break;
        }

        int k = 1;
        int len = 1 + w;
        
        while (1) {
            if (i - k < 0 || i + k + w > s_size - 1) break;

            if (s[i - k] == s[i + k + w]) len += 2;
            else break;    

            k++;
        }

        if (answer < len) answer = len;
    }

    return answer;
}

int main() {
    // q. 
    vector<string> v_s = {
        "abcdcba",          // 7
        "abacde",           // 3
        "ayxxybc",          // 4
        "aaa",              // 3
        "caxyyzyyxa",       // 9
    };

    for (int i = 0; i < v_s.size(); i++) {
        int answer = solution(v_s[i]);
        cout << "answer: " << answer << endl;
    }

    return 0;
}