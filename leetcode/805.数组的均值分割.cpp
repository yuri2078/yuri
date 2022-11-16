/*
 * @lc app=leetcode.cn id=805 lang=cpp
 *
 * [805] 数组的均值分割
 */

// @lc code=start
#include <unordered_set>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
	bool splitArraySameAverage(vector<int>& nums)
	{
		// 求和函数
		int sum = accumulate(nums.begin(), nums.end(), 0);
		const int size = nums.size(); // 获取数据的个数
		// 如果数据只有一个比不可能成立，直接返回
		if (size == 1) { 
			return false;
		}
		// 用每个数据 和 平均值的差替换原来的数据
		for (int& x: nums) {
			x = x * size - sum; // 计算每位和平均值的差值(以)
		}
		unordered_set<int> set; // 用来存放部分相加后不为0的数据
		int m = size >> 1;      // 相当于 除以 2
		// 先枚举 前一半数据
		// 忽略一个都不选 000
		for (int i = 1; i < 1 << m; i++) {
			int value = 0; // 初始值为0
			for (int j = 0; j < m; j++) {
				// 判断是不是需要添加的数据
				// i >> j 就是将 i 右移 j 位，再和 1 与，能得出，j 位是否为1
				// j位 是1 就要参与相加 不是就不用
				if (i >> j & 1) { 
					value += nums[j];
                }
			}
			// 如果部分和为0 ，那么说明一定存在另一个数组的和也是0，满足条件直接返回
			if (value == 0) {
				return true;
			}
			// 将不为0的数据添加，为后半部分做准备
			set.insert(value);
		}

		// 枚举剩下的部分
		for (int i = 1; i < 1 << (size - m) ; i++) {
			int value = 0;
			for (int j = 0; j < (size - m); j++) {
				if (i >> j & 1) {
					// 后半部分的值在 m + j里，而不是m
					value += nums[m + j];
                }
			}
			// 这里需要判断是不是全都选了才出现的 和是前一半的和的负数
			// 比如8 个数据，前一半 1111 和为 5 那么后一半 1111 结果必定是-5这不符合题意
			// 如果这里加起来的值的负数 出现在了另外一边，那么必定存在 这两波数据相加为0，直接返回 true
			
			if (value == 0 || (i != (1 << (size - m)) - 1) && set.count(-value)) {
				return true;
            }
		}
		return false;
    }
};
// @lc code=end

