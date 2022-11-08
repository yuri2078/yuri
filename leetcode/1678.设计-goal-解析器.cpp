/*
 * @lc app=leetcode.cn id=1678 lang=cpp
 *
 * [1678] 设计 Goal 解析器
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    string interpret(string command) {
		string ans;
		// 用来保存前一个字符
		char befor = 0;
		for (char ch: command) {
			if (ch == ')' && befor == '(') {
				// 如果这一个是) 并且前一个是( 则存放o
				ans += 'o';
			}

			// 不是括号就直接存放
			if (ch != '(' && ch != ')') {
				ans += ch;
			}

			// 保存上一个字符
			befor = ch;
		}
		return ans;
    }
};
// @lc code=end

