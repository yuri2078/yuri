/*
 * @lc app=leetcode.cn id=1662 lang=cpp
 *
 * [1662] 检查两个字符串数组是否相等
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
	{
		string word_1, word_2;
		
		for (string s_1: word1) {
			word_1 += s_1;
		}
		for (string s_2: word2) {
			word_2 += s_2;
		}
		return word_1 == word_2;
	}
};
// @lc code=end
