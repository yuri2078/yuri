#include <iostream>
using namespace std;
int main(void)
{
    int a = 10, b = 2;
    int k;
    k = a & b;
    cout << "对a和b进行按位与后的结果: " << k << "\n";
    k = a | b;
    cout << "对a和b进行按位与后的结果: " << k << "\n";
    k = a ^ b;
    cout << "对a和b进行按位与后的结果: " << k << "\n";
    k = ~a;
    cout << "对a进行按位求反后的结果: " << k << "\n";
    k = a << 1;
    cout << "对a进行左移1位后的结果: " << k << "\n";
    k = b >> 2;
    cout << "对b进行右移2位后的结果: " << k ;
    cout << endl;
    return 0;
}