#include <iostream>
using namespace std;
int main()
{
    int prime(int x);
    void resolve(int x);
    int x;
    cout << "请输入一个正整数:" << endl;
    cin >> x;
    resolve(x);
}
int prime(int x)
{
    for (int i = 2; i <= x/2;i++)
    {
        if(x%i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void resolve(int x)
{
    cout << x << '=';
    for (int i = 2; x != i;i++)
    {
        if(prime(i) && x%i == 0)
        {
            cout << i << '*';
            x = x / i;
            i--;
        }
    }
    cout << x;
}