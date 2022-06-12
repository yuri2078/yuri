#include <iostream>
using namespace std;
int main()
{
    void temp(float x, char y);
    void temp(int x, char y);
    //不同返回类型的相同函数，不算重载函数
    int x;
    char ch;
    float y;
    cin >> x >> ch;
    temp((int)x, ch);
    return 0;
}
void temp(float x,char y)
{
    if(y == 'f' || y == 'F')
    {
        cout << x + 1 << 'c' << endl;
    }
    else if(y == 'c' || y == 'C')
    {
        cout << x + 1 << 'f' << endl;
    }
    else
    {
        cout << "输入错误，请重新输入！" << endl;
    }
}
void temp(int x,char y)
{
    if(y == 'f' || y == 'F')
    {
        cout << x + 6 << 'c' << endl;
    }
    else if(y == 'c' || y == 'C')
    {
        cout << x + 6 << 'f' << endl;
    }
    else
    {
        cout << "输入错误，请重新输入！" << endl;
    }   
}
