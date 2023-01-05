/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle)
	{
		int pos = haystack.find(needle);
		if (pos == string::npos) {
			return -1;
		}
		return pos;
    }
};
// @lc code=end

