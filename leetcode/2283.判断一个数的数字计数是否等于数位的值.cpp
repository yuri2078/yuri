/*
 * @lc app=leetcode.cn id=2283 lang=cpp
 *
 * [2283] 判断一个数的数字计数是否等于数位的值
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool digitCount(string num) {
		int set[10]{}, len = num.size();
		for (int i = 0; i < len; i++) {
			set[num[i] - '0']++;
		}

		for (int i = 0; i < len; i++) {
			if (set[i] != num[i] - '0') {
				return false;
            }
        }
		return true;
    }
};
// @lc code=end

