#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    void sort(char name[5][20]);
    cout << "请输入5个英文姓名，每个名字用空格或回车间隔" << endl;
    char name[5][20];
    for (int i = 0; i < 5; i++)
    {
        cin >> name[i];
    }
    sort(name);
    cout << "按英文字母排序后的同学姓名为:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << name[i] << endl;
    }
    return 0;
}

void sort(char name[5][20])
{
    int i, k;
    char x[20];
    for (i = 1; i < 5; i++)
    {
        k = i - 1;
        strcpy(x, name[i]);
        while (k >= 0 && strcmp(x, name[k]) < 0)
        {
            strcpy(name[k + 1], name[k]);
            k--;
        }
        strcpy(name[k + 1], x);
    }
}