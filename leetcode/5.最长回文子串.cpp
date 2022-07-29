/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
using namespace std;
#include <vector>
class Solution
{
public:
    string longestPalindrome(string s) {
        string answer = "";
		int max_len = 0;
		vector<vector<bool>> dp(s.length(), vector<bool>(s.length()));
		for (int len = 1; len <= s.length(); len++)
		{
			for (int start = 0; start < s.length() && start + len <= s.length(); start++)
			{
				int end = start + len - 1;
				dp[start][end] = (len == 1 || (dp[start + 1][end - 1] || len == 2) && s[start] == s[end]);
				if (dp[start][end] && max_len < s.substr(start, len).length())
				{
					answer = s.substr(start, len);
					max_len = s.substr(start, len).length();
				}
			}
		}

		return answer;
    }
};
// @lc code=end

