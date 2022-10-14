/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{

		for (int i = 0; i < 9; i++)
		{
			int row[10]{};
			int col[10]{};
			int san[10]{};
			for (int j = 0; j < 9; j++)
			{
                if (board[i][j] != '.' && ( ++row[board[i][j] - '0']) > 1) {
                    return false;
                }
                if (board[j][i] != '.' && (++col[board[j][i] - '0']) > 1) {
                    return false;
                }
                if (board[j / 3 + 3 * (i / 3)][j % 3 + 3 * (i % 3)] != '.' && (++san[board[j / 3 + 3 * (i / 3)][j % 3 + 3 * (i % 3)] - '0']) > 1) {
                    return false;
                }
			}
		}
		return true;
	}
};
// @lc code=end
