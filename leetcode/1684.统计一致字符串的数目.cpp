/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 *
 * [1684] 统计一致字符串的数目
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
		int ans = 0;
		int map[26]{};
		for (char ch : allowed) {
            map[ch - 'a'] = 1;
        }
		for (string word : words) {
			bool flag = true;
			for (char ch : word) {
				if (map[ch - 'a'] != 1) {
					flag = false;
					break;
                }
			}
			flag ? ans++ : ans;
        }
		return ans;
    }
};
#include <iostream>

int main(int argc, const char **argv)
{
    
    return 0;
}
// @lc code=end

