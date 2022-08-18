#include <string>
#include <iostream>
#include <exception>
using namespace std;

#include <cmath>
#include <cctype>

class Solution
{
public:
    int myAtoi(string s) {
        int i = 0, f = 1;
        long long int sum = 0;

        while (i < s.length() && ' ' == s[i]){
            i++;
        }

        if (i < s.length() && (s[i] == '-' || s[i] == '+'))
        {
            f = s[i] == '-' ? -1 : 1;
            i++;
        }
        while (i < s.length() && isdigit(s[i]))
        {
            sum = sum * 10 + (s[i++] - '0');
            if((int)sum != sum){
                return f == 1 ? INT32_MAX : INT32_MIN;
            }
        }
        return (int)sum * f;
    }
};

int main(void)
{
    cout << Solution().myAtoi("-21474836460") << endl;
    cout << INT32_MAX << endl;
    return 0;
}