/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
		vector<string> ans; // 返回答案
		const int size = s.size();
		for (int i = 0; i < size; i++) {
			if (isAlpha(s[i])) {
				if (s[i] >= 'a') {
					ans.push_back(s);
					s[i] -= 32;
					ans.push_back(s);
				} else {
					ans.push_back(s);
					s[i] += 32;
					ans.push_back(s);
				}
			}
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
	bool isAlpha(char ch){
		return ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z');
	}
};
// @lc code=end

