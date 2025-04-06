// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
 
// Constraints:
// 1 <= n <= 45

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> vec(46, 0);
        vec[1] = 1;
        vec[2] = 2;

        for (int i = 3; i <= n; i++) {
            vec[i] = vec[i - 1] + vec[i - 2];
        }

        return vec[n];
    }
};

int main() {
    // q.
    int n = 45;

    Solution solution;
    int answer = solution.climbStairs(n);
    cout << "answer: " << answer << endl;

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 7.78MB 87.01%
 */