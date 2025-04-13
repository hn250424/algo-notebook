// Given a string s, find the length of the longest substring without duplicate characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vec(s.length(), 1);

        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                if (s[i] == s[j]) {
                    vec[i] = j - i;
                    break;
                } else if (j == s.length() - 1) {
                    vec[i] = j - i + 1;
                    break;
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < s.length(); i++) {
            int len = vec[i];
            int result = len;

            for (int j = i + 1; j < i + vec[i]; j++) {
                len--;
                if (vec[j] < len) result = min(j - i + vec[j], result);
            }

            answer = max(answer, result);
        }

        return answer;
    }
};

int main() {
    // g.
    vector<string> v_s = {
        "abcabcbb",     // 3
        "cdd",          // 2
        "au",           // 2
        "jlygy",        // 4
        "pwwkew",       // 3
        "uqinntq",      // 4
    };

    Solution sol;
    for (string s : v_s) {
        int answer = sol.lengthOfLongestSubstring(s);
        cout << "answer: " << answer << endl;
    }

    return 0;
}

/**
 * Runtime: 3ms 84.05%
 * Memory: 11.47MB 85.59%
 */