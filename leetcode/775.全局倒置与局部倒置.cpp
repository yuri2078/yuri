/*
 * @lc app=leetcode.cn id=775 lang=cpp
 *
 * [775] 全局倒置与局部倒置
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isIdealPermutation(vector<int>& nums)
	{
		const int size = nums.size();
		int minValue = nums[size - 1];
		for (int i = size - 3; i >= 0; i-- ) {
			if (nums[i] > minValue) {
				return false;
			}
			minValue = minValue > nums[i + 1] ? nums[i + 1] : minValue;
        }
		return true;
    }
};
// @lc code=end

