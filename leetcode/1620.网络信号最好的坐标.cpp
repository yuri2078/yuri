/*
 * @lc app=leetcode.cn id=1620 lang=cpp
 *
 * [1620] 网络信号最好的坐标
 */

// @lc code=start
#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> bestCoordinate(vector<vector<int>>& towers, int radius)
	{
		vector<int> ans(2);
		int maxSignal = 0;
		for (int i = 0; i <= 50; i++) {
			for (int j = 0; j <= 50; j++) {

				int signal = 0;
				
				for (vector<int> &tower : towers) {
					double distance = getDistance(tower, {i, j});
					if (distance <= radius) {
						signal += (int)(tower[2] / (1 + distance));
                    }
				}
				
                if (signal > maxSignal) {
                    maxSignal = signal;
                    ans[0] = i;
					ans[1] = j;
				} 
            }
        }

		return ans;
	}
	
	double getDistance(const vector<int>& p_1, const vector<int>&& p_2){
		return sqrt((p_1[0] - p_2[0]) * (p_1[0] - p_2[0]) + (p_1[1] - p_2[1]) * (p_1[1] - p_2[1]));
    }
};
// @lc code=end

