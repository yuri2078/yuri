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
        long long sum = 0;
        int f = 1;
        for (long unsigned int i = 0; i < s.length(); i++)
        {
            if(isdigit(s[i]))
            {
                if(i > 1 && s[i - 1] == '-'){
                    f = -1;
                }
                while (isdigit(s[i]) && i < s.length())
                {
                    sum = sum * 10 + (s[i] - 48);
                    i++;
                }
                break;
            }
        }
        long long int overFlow = f == 1 ? 2147483647 : -2147483648;
        return (int)sum == sum ? sum * f : overFlow;
    }
};

int main(void)
{
    cout << Solution().myAtoi("words and 987") << endl;
    return 0;
}