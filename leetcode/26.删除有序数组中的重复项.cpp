/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums)
	{
		// 默认第一个元素是绝对不会重复的
		int k = 1, size = nums.size();
		// 循环判断每个元素是否和他前一个元素相同
		for (int i = 1; i < size; i++) {
			// 不同就直接添加进去
			if (nums[i] != nums[i - 1]) {
				nums[k++] = nums[i];
            }
		}
		return k;
    }
};
// @lc code=end

