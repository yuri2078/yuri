/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
		vector<vector<int>> number(r, vector<int>(c, 0));
		if (r * c != mat.size() * mat[0].size()) {
			return mat;
        }
		int i = 0, j = 0;
		for (vector<int> row : mat) {
			for (int x : row) {
				number[i][j++] = x;
				if (j == c) {
					j = 0;
					i++;
                }
			}
		}
		
		return number;
    }
};
// @lc code=end

