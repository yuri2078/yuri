/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int x : nums) {
            ans = ans ^ x;
        }

		return ans;
    }
};
// @lc code=end