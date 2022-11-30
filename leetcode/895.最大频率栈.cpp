/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 */

// @lc code=start
#include <unordered_map>
#include <iostream>
using namespace std;


class FreqStack {
public:
	unordered_map<int, int> map;
	int num[20000];
	int size;
    FreqStack() {
		size = 0;
    }
    
    void push(int val) {
		map[val]++;
		num[size++] = val;
    }

	int pop()
	{
		int max = maxVal();
		int result = 0;
		for (int i = size - 1; i >= 0; i--) {
			if (num[i] == -1) {
				continue;
            }
			if (map[num[i]] == max) {
				map[num[i]]--;
				result = num[i];
				num[i] = -1;
				return result;
		    }
		}

		return result;
    }

	int maxVal()
	{
		int max = 0;
		for (auto val: map) {
			if (val.second > max) {
				max = val.second;
            }
		}

		return max;
    }
};


int main()
{
	FreqStack f;
	f.push(6);
	f.push(4);
	f.push(4);
	f.push(6);
	f.push(6);

	cout << f.pop() << endl;
	cout << f.pop() << endl;
	cout << f.pop() << endl;
    return 0;
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

