/*
 * @lc app=leetcode.cn id=2287 lang=cpp
 *
 * [2287] 重排字符形成目标字符串
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
	int rearrangeCharacters(string s, string target)
	{
		int res = 0;
		char map[26]{};
		for (char ch: s) {
			map[ch - 'a']++;
		}
		while (true) {
			for (char ch: target) {
				map[ch - 'a']--;
				if (map[ch - 'a'] < 0) {
					return res;
                }
			}
			res++;
        }

		return res;
    }
};
// @lc code=end

