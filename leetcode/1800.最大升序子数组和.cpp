/*
 * @lc app=leetcode.cn id=1800 lang=cpp
 *
 * [1800] 最大升序子数组和
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
		int max = nums[0];
		for (int i = 0; i < nums.size(); ) {
			int s = nums[i++];
            while (i < nums.size() && nums[i - 1] < nums[i]) {
				s += nums[i];
				i++;
			}
			if (max < s) {
				max = s;
			}
        }
		return max;
    }
};
// @lc code=end

