/*
 * @lc app=leetcode.cn id=1704 lang=cpp
 *
 * [1704] 判断字符串的两半是否相似
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool halvesAreAlike(string s)
	{
		const int size = s.size();
		char map[58]{};
		map['A' - 'A'] = 1;
		map['E' - 'A'] = 1;
		map['I' - 'A'] = 1;
		map['O' - 'A'] = 1;
		map['U' - 'A'] = 1;
		map['a' - 'A'] = 1;
		map['e' - 'A'] = 1;
		map['i' - 'A'] = 1;
		map['o' - 'A'] = 1;
		map['u' - 'A'] = 1;
		int len = 0;
		for (int i = 0; i < size; i++) {
			if (map[s[i] - 'A']) {
				i < size / 2 ? len++ : len--; 
            }
        }
		return len == 0;
    }
};



int main()
{
    cout << Solution().halvesAreAlike("textbook") << endl;
    return 0;
}
// @lc code=end

