/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> ans;
		for (int i = 1; i < numRows + 1; i++) {
			vector<int> row;
			for (int j = 0; j < i; j++) {
				if (j == 0 || j == i - 1) {
					row.push_back(1);
				} else {
					row.push_back(ans[i - 2][j] + ans[i - 2][j - 1]);
				}
			}
			ans.push_back(row);
		}
		return ans;
	}
};
// @lc code=end
