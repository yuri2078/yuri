/*
 * @lc app=leetcode.cn id=1812 lang=cpp
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool squareIsWhite(string coordinates) {
		int col = coordinates[0] - 'a';
		int row = coordinates[1] - '0';
		return col % 2 == 0 && row % 2 == 0 || col % 2 && row % 2;
    }
};
// @lc code=end

