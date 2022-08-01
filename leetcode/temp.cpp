#include <string>
#include <iostream>
using namespace std;


class Solution
{
public:
    string convert(string s, int numRows) {
        string newString[4] = {""};
        for (int i = 0; i < s.length();i = i + 2 * numRows - 3)
        {
            newString[0] = newString[0] + s[i];
        }

        n-2+n-2
        for (int i = 1; i < s.length();i = i + 2 * numRows - 3)
        {
            newString[0] = newString[0] + s[i];
        }

        for (int i = 2; i < s.length();i = i + 2 * numRows - 3)
        {
            newString[0] = newString[0] + s[i];
        }

        for (int i = 3; i < s.length();i = i + 2 * numRows - 3)
        {
            newString[0] = newString[0] + s[i];
        }
        return s;
    }
};

int main(void)
{
    cout << Solution().convert("PAYPALISHIRING", 3) << endl;

    return 0;
}