/*
 * @lc app=leetcode.cn id=1807 lang=cpp
 *
 * [1807] 替换字符串中的括号内容
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string evaluate(string s, vector<vector<string>>& knowledge)
	{
		int len = s.length(); // 字符串长度
		string res, temp;

		// 遍历一遍，添加字典
		unordered_map<string, string> map;
		for (vector<string> str: knowledge) {
			map[str[0]] = str[1];
		}

		// 遍历一遍字符串，遇到 ( 则开始准备替换
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') {
				i++;
				temp = "";

				// 结束后直接用字典内的东西替换就行
				while (s[i] != ')') {
					temp += s[i++];
				}
				
				if (map[temp] == "") {
					map[temp] = "?";
				}
				
				res += map[temp];
			} else {
				res += s[i];
            }
        }

		return res;
    }
};
// @lc code=end

