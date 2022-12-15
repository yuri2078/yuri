/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> res;
		for (int i = 1; i < (1 << 2 * n); i++) {
			// 判断是否符合条件
			if (result(i, 2 * n)) {
				// 符合条件就添加进去
				addData(i, res, 2 * n); 
			}
		}
		return res;
	}

	// 根据枚举的二进制代码添加数据
	void addData(int x, vector<string>& res, int n)
	{
		string s;
		for (int i = n - 1; i >= 0; i--) {
			if ((x & (1 << i)) == 0) {
				s += '(';
			} else {
				s += ')';
			}
		}
		res.push_back(s);
	}

	// 判断是否满足条件
	bool result(int x, int n)
	{
		int cur = 0;
		for (int i = n - 1; i >= 0 && cur >= 0; i--) {
			if ((x & (1 << i)) == 0) {
				cur++;
			} else {
				cur--;
			}
		}
		return cur == 0;
	}
	
};

// @lc code=end

