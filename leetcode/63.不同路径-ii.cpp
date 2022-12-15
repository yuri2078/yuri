/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> dp(m, vector<int>(n));
		// 从起点到 这一行 和 这一列只有一种方法
		bool flag = false;
		for (int i = 0; i < m; i++) {
			if (flag || obstacleGrid[i][0]) {
				flag = true;
				dp[i][0] = 0;
			} else {
				dp[i][0] = 1;
            }
		}
		
		flag = false;
		for (int i = 0; i < n; i++) {
			if (flag || obstacleGrid[0][i]) {
				flag = true;
				dp[0][i] = 0;
			} else {
				dp[0][i] = 1;
            }
		}


		// 从 1 1 开始遍历
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j]) {
					dp[i][j] = 0;
				} else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
		return dp[m - 1][n - 1];
    }
};
// @lc code=end

