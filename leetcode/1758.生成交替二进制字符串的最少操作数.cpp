/*
 * @lc app=leetcode.cn id=1758 lang=cpp
 *
 * [1758] 生成交替二进制字符串的最少操作数
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
		int cur_1 = 0, cur_2 = 0, i = 0;
		char str[] = {'0', '1'};
		for (char ch: s) {
			if (ch == str[i & 1]) {
				cur_2++;
			} else {
				cur_1++;
			}
			i++;
		}
		return min(cur_1, cur_2);
    }
};

// @lc code=end

