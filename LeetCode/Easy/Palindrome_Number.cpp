// Given an integer x, return true if x is a palindrome, and false otherwise.

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.

// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 
// Constraints:

// -231 <= x <= 231 - 1
 
// Follow up: Could you solve it without converting the integer to a string?

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str_x = to_string(x);
        reverse(str_x.begin(), str_x.end());

        if (str_x == to_string(x)) return true;
        else return false;
    }
};

int main() {
    // g.
    int x = 121;

    Solution sol;
    int answer = sol.isPalindrome(x);
    cout << "answer: " << answer << endl;

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 10.96MB 10.00%
 */