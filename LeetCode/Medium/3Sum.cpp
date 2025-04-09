// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

// Example 2:
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.

// Example 3:
// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
 
// Constraints:
// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105

#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> set;

        for (int i = 0; i < nums.size() - 1; i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    set.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
            }
        }

        vector<vector<int>> answer;
        for (const auto& s : set) {
            answer.push_back(vector<int>(s.begin(), s.end()));
        }

        return answer;
    }
};

int main() {
    // g.
    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // vector<int> nums = {0, 0, 0, 0};
    vector<int> nums = {-2, 0, 1, 1, 2};
    // vector<int> nums = {-1, 0, 1, 0};
    // vector<int> nums = {1, 2, -2, -1};

    Solution s;
    vector<vector<int>> answer = s.threeSum(nums);
    cout << "answer: " << endl;
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/**
 * Runtime: 1168ms 15.99%
 * Memory: 293.61MB 13.27%
 */