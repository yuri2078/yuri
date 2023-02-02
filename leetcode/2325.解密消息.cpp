/*
 * @lc app=leetcode.cn id=2325 lang=cpp
 *
 * [2325] 解密消息
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
		char map[26]{}, ch = 'a';
		
		for (char s: key) {
			if (s != ' ' && map[s - 'a'] == 0) {
				map[s - 'a'] = ch++;
            }
		}
		for (int i = 0; i < message.size(); i++) {
			if (message[i] != ' ') {
				message[i] = map[message[i] - 'a'];
            }
        }
		return message;
    }
};
// @lc code=end

