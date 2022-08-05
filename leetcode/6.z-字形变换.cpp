/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string convert(string s, int numRows) {
        if (numRows == 1){
            return s;
        }

        vector<string> newString(numRows,"");
        int j = 0;
        bool flag = true;
        for (int i = 0; i < s.length(); i++)
        {
            newString[j] = newString[j] + s[i];
            flag ? j++ : j--;
            if(j == numRows){
                j = numRows - 2;
                flag = false;
            }

            if(j == -1){
                j = 1;
                flag = true;
            }
        }
        for (int i = 1; i < numRows;i++)
        {
            newString[0] = newString[0] + newString[i];
        }
        return newString[0];
    }
};


// @lc code=end

