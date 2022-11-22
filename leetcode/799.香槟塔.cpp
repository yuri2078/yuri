/*
 * @lc app=leetcode.cn id=799 lang=cpp
 *
 * [799] 香槟塔
 */

// @lc code=start
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
		double ans = 0;
		int need = 0;
		for (int i = 0; i < query_row; i++) {
			need += pow(2, i);
		}
		if (query_glass == 0 || query_glass == query_row) {
			if (poured > need) {
				return (double)(poured - need) / (double)(2 * query_row);
			} else {
				return 0;
            }
		}
		need = 0;
        for (int i = 1; i <= query_row; i++) {
			need += i;
		}
		
		return ans;
    }
};




int main()
{
    cout << "ans : " << Solution().champagneTower(8, 3, 0) << endl;
    return 0;
}
// @lc code=end

