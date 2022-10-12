/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		int money = prices[0], max_money = 0;
		for (int i=0; i<prices.size(); i++) {
			int temp = max(0, prices[i] - money);
			max_money = max(max_money,temp);
			money = min(money,prices[i]);
        }
        return max_money;
    }
};
// @lc code=end

