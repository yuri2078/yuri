/*
 * @lc app=leetcode.cn id=2293 lang=cpp
 *
 * [2293] 极大极小游戏
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
	int minMaxGame(vector<int>& nums)
	{
		int size = nums.size() / 2;
		if (size == 0) {
			return nums[0];
		}
		while (size) {
			for (int i = 0; i < size; i++) {
				if (i % 2) {
					nums[i] = max(nums[2 * i], nums[2 * i + 1]);
				} else {
					nums[i] = min(nums[2 * i], nums[2 * i + 1]);
                }
			}
			size /= 2;
        }
		return nums[0];
    }
};


// @lc code=end

