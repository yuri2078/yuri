/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost)
	{
		const int size = cost.size();
		vector<int> dp(size + 1);
		dp[1] = dp[0] = 0;
		for (int i = 2; i <= size; i++) {
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
		return dp[size];
    }
};
// @lc code=end

