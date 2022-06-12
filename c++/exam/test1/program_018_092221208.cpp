#include <iostream>
using namespace std;
int main()
{
    int n;
    void print(int a[], int n);
    void reverse(int a[], int n);
    cout << "请输入数组的容量";
    cin >> n;
    int number[n];
    cout << "请输入一个数组:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }
    cout << "原始数组是:" << endl;
    print(number, n);
    reverse(number, n);
    cout << endl
         << "逆序后的数组是:" << endl;
    print(number, n);
    return 0;
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
}

void reverse(int a[], int n)
{
    int l = 0, h = n - 1, t;
    while (l != h)
    {
        t = a[l];
        a[l] = a[h];
        a[h] = t;
        l++;
        h--;
    }
}