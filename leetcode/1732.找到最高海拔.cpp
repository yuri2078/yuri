/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
		int ans = 0;
		int gain_ = 0;
        for (int x : gain) {
			gain_ += x;
			ans = ans > gain_ ? ans : gain_;
        }
		return ans;
    }
};
// @lc code=end

