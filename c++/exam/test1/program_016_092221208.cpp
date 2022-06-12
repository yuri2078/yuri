#include <iostream>
using namespace std;
int main()
{
    void print(int a[3][3]);
    int a[3][3], i, j, t;
    cout << "输入矩阵：" << endl;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "原始矩阵是：" << endl;
    print(a);
    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
    }
    cout << "转置后的矩阵是：" << endl;
    print(a);
    return 0;
}

void print(int a[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}