// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example 1:

// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:

// Input: list1 = [], list2 = []
// Output: []

// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    unordered_map<char, vector<char>> map = {
        { '2', vector<char>{'a', 'b', 'c'} },
        { '3', vector<char>{'d', 'e', 'f'} },
        { '4', vector<char>{'g', 'h', 'i'} },
        { '5', vector<char>{'j', 'k', 'l'} },
        { '6', vector<char>{'m', 'n', 'o'} },
        { '7', vector<char>{'p', 'q', 'r', 's'} },
        { '8', vector<char>{'t', 'u', 'v'} },
        { '9', vector<char>{'w', 'x', 'y', 'z'} },
    };

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        backtrack(result, digits, 0, "");
        return result;
    }

private:
    void backtrack(vector<string>& result, string digits, int digits_idx, string str) {
        char c = digits[digits_idx];

        for (int i = 0; i < map[c].size(); i++) {
            string next = str + map[c][i];
            if (digits_idx == digits.length() -1) result.push_back(next);
            else backtrack(result, digits, digits_idx + 1, next);
        }
    }
};

int main() {
    // g.
    string digits = "23";
    
    Solution sol;
    vector<string> answer = sol.letterCombinations(digits);
    cout << "answer: ";
    for (string s : answer) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 9.01MB 87.26%
 */