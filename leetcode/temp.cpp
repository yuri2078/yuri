#include <string>
#include <iostream>
#include <exception>
using namespace std;

#include <cmath>

class Solution
{
public:
    int reverse(int x) {
        long long int s = 0;
        while (x)
        {
            s = s * 10 + x % 10;
            x = x / 10;
        }

        return (int)s == s ? s : 0;
    }
};

int main(void)
{
    cout << Solution().reverse(122) << endl;

    try
    {
        4 / 0;
    }
    catch(std::exception &e)
    {
        cout << "和和咯" << endl;
    }

    return 0;
}