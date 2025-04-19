// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:

// Input: n = 1
// Output: ["()"]
 
// Constraints:

// 1 <= n <= 8

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        backtrack(answer, n, "", 0, 0);
        return answer;
    }

private:
    void backtrack(vector<string>& answer, int n, string current, int open, int close) {
        if (current.length() == 2 * n) {
            answer.push_back(current);
            return;
        }

        if (open < n) backtrack(answer, n, current + "(", open + 1, close);
        if (close < open) backtrack(answer, n, current + ")", open, close + 1);
    }
};

int main() {
    // g.
    int n = 3;

    Solution sol;
    vector<string> answer = sol.generateParenthesis(n);
    cout << "answer: ";
    for (string s : answer) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}

/**
 * Runtime: 2ms 82.46%
 * Memory: 15.17MB 35.94%
 */