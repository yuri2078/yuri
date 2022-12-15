/*
 * @lc app=leetcode.cn id=1827 lang=cpp
 *
 * [1827] 最少操作使数组递增
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
		int res = 0;
		const int size = nums.size();
		for (int i = 1; i < size; i++) {
			if (nums[i] <= nums[i - 1]) {
				res += nums[i - 1] - nums[i] + 1;
				nums[i] += nums[i - 1] - nums[i] + 1;
            }
        }
		return res;
    }
};
// @lc code=end

