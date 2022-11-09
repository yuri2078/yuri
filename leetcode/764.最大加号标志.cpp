/*
 * @lc app=leetcode.cn id=764 lang=cpp
 *
 * [764] 最大加号标志
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
		int ans = 1;
		vector<vector<int>> map(n, vector<int>(n));
		if (n * n == mines.size()) {
			return 0;
        }
		
		for (vector<int> mine : mines) {
			map[mine[0]][mine[1]] = 1;
		}
		
		while (true)
		{
			label:
            for (int i = ans; i < n - ans; i++) {
                for (int j = ans; j < n - ans; j++) {
					if (check(ans, i, j, map)) {
						ans++;
						goto label;
                    }
                }
			}
			break;
        }

		return ans;
	}
	bool check(int n, int row, int col, const vector<vector<int>>& map)
	{
		for (int i = -n; i <= n; i++) {
			if (map[row + i][col] || map[row][col + i]) {
				return false;
            }
		}
		return true;
    }
};

            
// @lc code=end

