// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal substring consisting of non-space characters only.

// Example 1:
// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.

// Example 2:
// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.

// Example 3:
// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.
 
// Constraints:
// 1 <= s.length <= 104
// s consists of only English letters and spaces ' '.
// There will be at least one word in s.

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        bool counting = false;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (! counting) {
                if (s[i] == ' ') {
                    continue;
                } else {
                    counting = true;
                    cnt++;
                }
            } else {
                if (s[i] != ' ') {
                    cnt++;
                } else {
                    return cnt;
                }
            }
        }

        return cnt;
    }
};

int main() {
    // q.
    string s = "   fly me   to   the moon  ";

    Solution solution;
    int answer = solution.lengthOfLastWord(s);
    cout << "answer: " << answer << endl;

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 8.90MB 66.44%
 */