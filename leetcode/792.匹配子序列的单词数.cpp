/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
		const int num = words.size();
		int ans = 0;
		for (int i = 0; i < num; i++) {
			int pos = -1;
			bool flag = true;
			for (char ch : words[i]) {
				pos = s.find(ch, pos + 1);
				if (pos == string::npos) {
					flag = false;
					break;
                }
			}
			if (flag) {
				ans++;
            }
		}
		return ans;
    }
};
// @lc code=end

