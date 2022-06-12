#include <iostream>
using namespace std;
int main()
{
    void sort(int a[], int n);
    int number[10] = {213428, 723, 10, 1, 41, 6547, 423, 15466, 3231, 14334};
    cout << "按位数排列后为：" << endl;
    sort(number, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << number[i] << endl;
    }
    return 0;
}

void sort(int a[], int n)
{
    int i, k, x;
    for (i = 1; i < n; i++)
    {
        k = i - 1;
        x = a[i];
        while (k >= 0 && x < a[k])
        {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = x;
    }
}
