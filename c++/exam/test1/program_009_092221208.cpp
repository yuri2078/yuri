#include <iostream>
using namespace std;
int main()
{
    void print(int x);
    int x;
    cout << "请输入等边三角形的值: ";
    cin >> x;
    print(x);
}
void print(int x)
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x - i; j++)
        {
            cout << ' ';
        }
        for (j = 0; j < i + 1; j++)
        {
            cout << '*' << ' ';
        }
        cout << endl;
    }
}