#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;//这种接收方式遇到空格停止
    cout << str << endl;
    cin.clear();//清空输入缓冲区
    getline(cin, str);//这个就可以接收空格了
    cout << str << endl;
    return 0;
}