/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include <iterator>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		vector<bool> row(matrix.size(), false);
		vector<bool> col(matrix[0].size(),false);
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (!matrix[i][j]) {
					row[i] = true;
					col[j] = true;
                }
            }
		}
		for (int i = 0;  i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (row[i] == 1 || col[j] == 1) {
					matrix[i][j] = 0;
                }
            }
		}
    }
};
// @lc code=end

