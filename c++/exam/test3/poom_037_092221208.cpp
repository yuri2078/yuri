#include <iostream>
#include <cstring>
template <class T>
T maxn(const T *temp, int num)
{
    T max = temp[0];
    for (int i = 1; i < num;i++)
    {
        if(max < temp[i])
        {
            max = temp[i];
        }
    }
    return max;
}

const char *maxn(const char **t, int num)
{
    int max = 0;
    for (int i = 1; i < num;i++)
    {
        if(strlen(t[max]) < strlen(t[i]))
        {
            max = i;
        }
    }
    return t[max];
}

int main()
{
    int iarray[6]={11,22,43,14,-1,99};
    double darray[4]={88.6,33.0,915,15.8};
    const char *charray[5] = {"heyyroup", "sunshineradio", "Apm32", "ilovez'girl", "up_play1313"};
    std::cout << "最大的整数：" << maxn(iarray,6) << "\n";
    std::cout << "最大的浮点数：" << maxn(darray,4) << "\n";
    std::cout << "最长的字符串：" << maxn(charray,5) << "\n";
    return 0;
}