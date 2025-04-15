// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

// Example 1:

// Input: s = "()"

// Output: true

// Example 2:

// Input: s = "()[]{}"

// Output: true

// Example 3:

// Input: s = "(]"

// Output: false

// Example 4:

// Input: s = "([])"

// Output: true

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (char _ : s) {
            switch (_) {
                case '(': 
                case '{': 
                case '[':
                    stack.push(_);
                    break;

                case ')':
                    if (stack.empty() || stack.top() != '(') return false;
                    stack.pop();
                    break;

                case '}':
                    if (stack.empty() || stack.top() != '{') return false;
                    stack.pop();
                    break;

                case ']':
                    if (stack.empty() || stack.top() != '[') return false;
                    stack.pop();
                    break;
            }
        }

        return stack.empty();
    }
};

int main() {
    // g.
    string s = "()[]{}";

    Solution sol;
    bool answer = sol.isValid(s);
    cout << "answer: " << answer << endl;

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 8.58MB 96.23%
 */