/*
 * @lc app=leetcode.cn id=1668 lang=cpp
 *
 * [1668] 最大重复子字符串
 */

// @lc code=start
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
		int ans = 0;
		string s = word;
		while (sequence.find(s) != sequence.npos) {
			ans++;
			s += word;
        }
		return ans;
    }
};
// @lc code=end

