/*
 * @lc app=leetcode.cn id=1803 lang=cpp
 *
 * [1803] 统计异或值在范围内的数对有多少
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
		int res = 0, size = nums.size(), mod;
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				
				mod = nums[i] ^ nums[j];
				if (mod >= low && mod <= high) {
					res++;
                }
            }
        }
		return res;
    }
};
// @lc code=end

