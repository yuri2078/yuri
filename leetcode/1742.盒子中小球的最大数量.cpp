/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
		int max_val = 0;
		unordered_map<int, int> map;
		for (int i = lowLimit; i <= highLimit; i++) {
			int val = result(i);
			map[val]++;
			if (map[val] > max_val) {
				max_val = map[val];
            }
        }

		return max_val;
	}

	int result(int x)
	{
		int ans = 0;
		while (x) {
			ans += x % 10;
			x /= 10;
		}
		return ans;
    }
};
// @lc code=end

