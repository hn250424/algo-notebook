// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 
// Example 1:
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

// Example 2:
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// Example 3:
// Input: s = "A", numRows = 1
// Output: "A"
 
// Constraints:
// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> vec(numRows);

        int vec_idx = 0;
        int delta = 1;
        for (int i = 0; i < s.length(); i++) {
            vec[vec_idx] += s[i];

            vec_idx += delta;
            if (vec_idx == numRows - 1) delta = -1;
            else if (vec_idx == 0) delta = 1;
        }

        string answer = "";
        for (string v: vec) {
            answer += v;
        }

        return answer;
    }
};

int main() {
    // q.
    string s = "PAYPALISHIRING";
    int numRows = 4;

    Solution sol;
    string answer = sol.convert(s, numRows);
    cout << "answer: " << answer << endl;

    return 0;
}

/**
 * Runtime: 1ms 83.92%
 * Memory: 14.38MB 34.24%
 */