/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n));
		// 从起点到 这一行 和 这一列只有一种方法
		for(int i=0;i<m;i++){
            dp[i][0] = 1;
		}
		for (int i = 0; i < n; i++) {
			dp[0][i] = 1;
		}

		// 从 1 1 开始遍历
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			// 到达当前位置的路径数等于自己左边和上边的路径数相加
            }
        }
		return dp[m - 1][n - 1];
    }
};
// @lc code=end

