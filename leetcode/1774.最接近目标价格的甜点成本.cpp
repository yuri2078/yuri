/*
 * @lc app=leetcode.cn id=1774 lang=cpp
 *
 * [1774] 最接近目标价格的甜点成本
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
		int res = target, n = baseCosts.size(), m = toppingCosts.size();
		sort(toppingCosts.begin(), toppingCosts.end(), [](int x, int y){
            return x > y;
        });
		sort(baseCosts.begin(), baseCosts.end());
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 1 << m; j++) {
				int sum = 0;
				for (int k = 0; k < m; k++) {
					if (j & (1 << k)) {
						sum += toppingCosts[i];
                    }
                }
            }
        }
		return res;
	}

	int result(int base, int costs)
	{
		int res = 0;
		if (base - costs < 0) {
			return 1;
        }

		return res;
    }
};
// @lc code=end

