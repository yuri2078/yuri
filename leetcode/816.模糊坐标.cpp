/*
 * @lc app=leetcode.cn id=816 lang=cpp
 *
 * [816] 模糊坐标
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<string> ambiguousCoordinates(string s)
	{
		vector<string> ans;
		const int size = s.size();
		for (int i = 1; i < size - 2; i++) {
			string s_1 = s.substr(1, i);
			string s_2 = s.substr(i + 1, size - i - 2);
			const int size_1 = s_1.size();
			const int size_2 = s_2.size();
			for (int j = 0; j < size_1; j++) {
				string temp_1 = s_1;
				if (j != 0) {
					temp_1.insert(temp_1.begin() + j, '.');
                }
				if (result(temp_1)) {
					for (int k = 0; k < size_2; k++) {
						string temp_2 = s_2;
						if (k != 0) {
							temp_2.insert(temp_2.begin() + k, '.');
                        }

						if (result(temp_2)) {
							string str;
							str = str + "(" + temp_1 + ", " + temp_2 + ")";
							ans.push_back(str);
						}
					}
					
				}
			}
		}

		return ans;
	}

	bool result(string s)
	{
		bool flag = false;
		int i;
		const int size = s.size();
		if (size > 1 && s[0] == '0' && s[1] != '.') {
			return false;
		}
		for (i = 0; i < size; i++) {
			if (s[i] == '.') {
				flag = true;
			}

			if (s[i] == '0') {
				if (flag && i + 1 == size) {
					return false;
				}
			}
		}
		return true;
	}
};

int main(int argc, const char** argv)
{
	Solution().ambiguousCoordinates("(01000)");
	// cout << Solution().result("00.01") << endl;
	return 0;
}
// @lc code=end
