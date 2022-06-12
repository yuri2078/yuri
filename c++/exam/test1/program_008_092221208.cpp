#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    void turn(char s[80]);
    char s[80];
    cout << "输入一个整数: ";
    cin >> s;
    turn(s);
    cout << "反转整数后结果: " << s;
}
void turn(char s[80])
{
    int l = 0, h = strlen(s) - 1;
    char t;
    while (l < h)
    {
        t = s[l];
        s[l] = s[h];
        s[h] = t;
        l++;
        h--;
    }
}