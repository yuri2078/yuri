/*
 * @lc app=leetcode.cn id=1796 lang=cpp
 *
 * [1796] 字符串中第二大的数字
 */

// @lc code=start
#include <cstdint>
#include <string>

using namespace std;

class Solution {
public:
    int secondHighest(string s) {
		int res = -1, max_val = -1;
		for (char ch: s) {
			if (ch >= '0' && ch <= '1') {
				if (max_val < ch - 48) {
					res = max_val;
					max_val = ch - 48;
				} else {
					res = max(res, ch - 48);
                }
            }
        }
		return res;
    }
};
// @lc code=end

