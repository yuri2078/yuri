/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int numSubarrayBoundedMax(vector<int>& nums, int left, int right)
	{
		int ans = 0, left_ = -1, right_ = -1; // 设置左边界一开始为 -1 当 right_ 为0 时正好加1
		const int size = nums.size();
		for (int i = 0; i < size; i++) {
			if (nums[i] >= left && nums[i] <= right) {
				right_ = i; // 当结果符合条件时 更新右边界
			} else if (nums[i] > right) {
				left_ = i; // 不和条件时更新
				right_ = -1;
			}
			// 组合的结果就是他们的差值
			// 当nums[i] < left 时，只会添加上一次的结果
			if (right_ != -1) {
				ans += right_ - left_;
            }
		}
		return ans;
	}
};

// int main()
// {
// 	vector<int> v;
// 	v.push_back(2);
// 	v.push_back(1);
// 	v.push_back(4);
// 	v.push_back(3);
// 	cout << Solution().numSubarrayBoundedMax(v, 2, 3) << endl;
// 	return 0;
// }
// @lc code=end
