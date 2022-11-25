/*
 * @lc app=leetcode.cn id=809 lang=cpp
 *
 * [809] 情感丰富的文字
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
		int res = 0;
		const int size_s = s.size();
        for (string word : words) {
			int start_s = 0, start_word = 0; // 设置两个字符串的起点
			const int size_word = word.size();
			while (start_word < size_word && start_s < size_s) {
				// 当两个字符串不相同时直接推出循环
				if (s[start_s] != word[start_word]) {
					break;
				}
				int times_s = times(s, start_s); // 获取当前字符在s中重复的个数
				int times_ss = times(word, start_word); // 获取当前字符在word中重复的个数
				// 当在s中重复超过2次并且后者重复次数小于前者 或者 两者重复次数相同时继续比较
				if ((times_s > 2 && times_s > times_ss) || times_s == times_ss) {
					start_s += times_s;
					start_word += times_ss;
				// 否则推出循环
				} else {
					break;
                }
			}
			// 判断两个字符串是否都以遍历完毕
			if (start_word == size_word && start_s == size_s) {
				res++;
            }
        }
		return res;
	}

	// 获取指定位置字母出现的个数
	int times(const string& s, int pos)
	{
		int res = 1;
		const int size = s.size();
		while (pos < size - 1 && s[pos] == s[pos + 1]) {
			pos++;
			res++;
		}
		return res;
    }
};

// @lc code=end

