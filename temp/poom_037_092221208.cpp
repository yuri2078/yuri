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


