/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> stack;
		unordered_map<char, char> map;
		map['('] = ')';
		map['['] = ']';
		map['{'] = '}';
		for (char ch: s) {
			if (ch == '(' || ch == '{' || ch == '[') {
				stack.push(ch);
			} else {
				if (stack.empty() || ch != map[stack.top()]) {
					return false;
				} else {
					stack.pop();
                }
            }
        }
		return stack.empty();
	}
};
// @lc code=end
