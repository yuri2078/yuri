/*
 * @lc app=leetcode.cn id=1798 lang=cpp
 *
 * [1798] 你能构造出连续值的最大数目
*/

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int getMaximumConsecutive(vector<int>& coins)
	{
		/*假设我们可以构建 0 - m
		如果我们需要构建m + 1,我们可以找一个数等于 m + 1
		或者找一个小于或者等于m的数。那么就可以组合构建，例如我们可以构建0 - 99
        如果我们需要构建100 那么我么找到一个 0 - 100的数就可以构建，比如99 + 1 98 + 2
        所以对于已经排完序的数列，如果当前数大于可以排成的数 + 1 那么就不可能排成
        如果小于那么就可以直接加上这个数，因为能够构造 0 - m 那么就可以构造 0 - m + n
        */ 
		int ans = 0;
		sort(coins.begin(), coins.end());
		for (int x: coins) {
			if (x > ans + 1) {
				break;
			}
			ans += x;
        }
		return ans + 1;
    }
};
// @lc code=end

