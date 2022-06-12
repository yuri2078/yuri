#include <iostream>
using namespace std;
int main()
{
    int gys(int x, int y);
    int gbs(int x, int y);
    int x, y;
    cout << "-------求最大公约数和最小公倍数-------" << endl;
    cout << "请输入两个正整数:";
    cin >> x >> y;
    cout << "最大公约数: " << gys(x, y) << endl;
    cout << "最小公倍数: " << gbs(x, y) << endl;
}
int gys(int x, int y)
{
    int k = x;
    while (x % k || y % k)
    {
        k--;
    }
    return k;
}
int gbs(int x, int y)
{
    int k = x;
    while (k % x || k % y)
    {
        k++;
    }
    return k;
}