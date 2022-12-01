/*
 * @lc app=leetcode.cn id=1779 lang=cpp
 *
 * [1779] 找到最近的有相同 X 或 Y 坐标的点
 */

// @lc code=start
#include <cmath>
#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
		int result = -1, min_val = INT32_MAX;
		const int size = points.size();
		for (int i = 0; i < size; i++) {
			if (x == points[i][0]) {
                int val = abs(points[i][1] - y);
                if (val < min_val) {
                    result = i;
                    min_val = val;
                }
			}
			if (y == points[i][1]) {
                int val = abs(points[i][0] - x);
                if (val < min_val) {
                    result = i;
                    min_val = val;
                }
            }
        }
		return result;
    }
};
// @lc code=end

