/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		vector<string> ans;
		// 初始化数字对应的字符串
		const char num[][5]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		// 将容器的size 存储，每次判断都调用函数会影响执行时间
		const int size = digits.size();

		//如果长度为 0 直接返回空的容器就行
		if (size == 0) {
			return ans;
        }

		//定义循环次数 输入n个数据，就需要循环 4 ^ n 次方（不包括7 和 9 就是 3 ^ n)
		const int times = pow(4, size);
		for (int i = 0; i < times; i++) {
			string s;
			int k = times / 4;
			// 将times / 4 就能得到 第一位数据重复的次数
			// 从第二位开始重复次数 就是上一位的重复次数 / 4
			for (int j = 0; j < size; j++) {
				char ch = num[digits[j] - '0'][(i / k) % 4]; // %4 防止 k 变小 而 i 变大时，数组越界
				if (!ch) {
					// 遇到 \0 了，就代表有一位（不是 7 和 9)超过限制了，直接退出
					break;
				}
				s += ch;
				k = k / 4;
			}
			//当添加的数据长度不等于size时，直接跳过添加
			if (s.size() != size) {
				continue;
            }
			ans.push_back(s);
		}
		return ans;
	}
};
// @lc code=end
