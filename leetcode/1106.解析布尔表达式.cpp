/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 *
 * [1106] 解析布尔表达式
 */

// @lc code=start
#include <ostream>
#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>


using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
		stack<char> s;
		
		for (char ch : expression) {
			if (ch == ',') {
				continue;
			}

			if (ch == ')') {
				vector<char> v;
				while (s.top() != '(') {
					v.push_back(s.top());
					s.pop();
				}
				s.pop();
				bool ans = result(s.top(), v);
				s.pop();
				s.push(ans ? 't' : 'f');
			} else {
				s.push(ch);
            }
        }
		return s.top()  == 't' ? true : false;
	}

	bool result(char ch, const vector<char>& v)
	{
		unordered_map<char, bool> map{{'f', false}, {'t', true}};
		bool ans = map[v[0]];
		if (ch == '!') {
			return !map[v[0]];
		}
		for (char c : v) {
			if (ch == '|') {
				ans = ans || map[c];
			} else {
				ans = ans && map[c];
            }
        }
		return ans;
    }
};



int main(int argc, const char **argv)
{
	cout << Solution().parseBoolExpr("!(&(f,t))") << endl;
	// vector<char> v{'f'};
	// cout << Solution().result('&',  v) << endl;
    return 0;
}
// @lc code=end

