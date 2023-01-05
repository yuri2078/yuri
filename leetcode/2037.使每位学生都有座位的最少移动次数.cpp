/*
 * @lc app=leetcode.cn id=2037 lang=cpp
 *
 * [2037] 使每位学生都有座位的最少移动次数
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
		int res = 0, n = seats.size();
		sort(seats.begin(), seats.end());
		sort(students.begin(), students.end());
		for (int i = 0; i < n; i++) {
			res += abs(seats[i] - students[i]);
        }
		return res;
    }
};
// @lc code=end

