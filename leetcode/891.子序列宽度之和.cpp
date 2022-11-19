/*
 * @lc app=leetcode.cn id=891 lang=cpp
 *
 * [891] 子序列宽度之和
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
		long long ans = 0, mod = 1e9 + 7;
		const int size = nums.size();
		sort(nums.begin(), nums.end());
		vector<long long> pow(size, 1);
		for (int i = 1; i < size; i++) {
			pow[i] = pow[i - 1] * 2 % mod;
		}

		for (int i = 0; i < size; i++) {
			long long res = nums[i] * (pow[i] - pow[size - i - 1]) % mod;
			ans = (ans + res) % mod;
        }
		return ans;
    }
};
// 1 2 3
// 1 2 1 3
// 2 3
// @lc code=end

