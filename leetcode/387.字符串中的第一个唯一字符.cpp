/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

#include <memory>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
	int firstUniqChar(string s)
	{
		//查找字符，当从前查找的位置等于从后查找时，说明只有一个
		for (char ch : s) {
			if (s.find(ch) == s.rfind(ch)) {
				return s.find(ch);
            }
        }
		return -1;
    }
};
// @lc code=end

