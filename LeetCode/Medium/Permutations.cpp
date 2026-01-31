// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:

// Input: nums = [1]
// Output: [[1]]

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void dfs(vector<int>& nums, vector<vector<int>>& answer, vector<int>& path, vector<int>& memo, int index) {
		if (path.size() == nums.size()) {
			answer.push_back(path);
			return;
		}

		for (int i = 0; i < nums.size(); ++i) {
			if (memo[i] == 1) continue;

			path.push_back(nums[i]);
			memo[i] = 1;

			dfs(nums, answer, path, memo, index + 1);

			path.pop_back();
			memo[i] = 0;
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> answer;
		vector<int> path;
		vector<int> memo(nums.size(), 0);
		dfs(nums, answer, path, memo, 0);
		return answer;
	}
};

int main() {
	vector<int> nums = {1, 2, 3};

	Solution s;
	vector<vector<int>> answer = s.permute(nums);

	printf("answer: \n");
	for (int i = 0; i < answer.size(); ++i) {
		for (int j = 0; j < answer[i].size(); ++j) {
			printf("%d ", answer[i][j]);
		}
		printf("\n");
	}

	return 0;
}

// Runtime: 0ms 100.00%
// Memory: 10.62MB 50.15%