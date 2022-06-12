#include <iostream>
#include <string>

template <class T>
T sum(const T *array, int num)
{
    T all = 0;
    for (int i = 0; i < num;i++)
    {
        all = all + array[i];
    }
    return all;
}

template <class T1, class T2>
double sum(const T1 *array_1, int num_1,const T2 *array_2, int num_2)
{
    double all = 0;
    for (int i = 0; i < num_1; i++)
    {
        all = all + array_1[i];
    }
    
    for (int i = 0; i < num_2; i++)
    {
        all = all + array_2[i];
    }
    return all;
}

std::string sum(const char *array_1, const char *array_2)
{
    std::string temp(array_1);
    return temp + array_2;
}

int main()
{
    int iArr[]={1,2,3,4,5,6,7,8,9,10};
    double dArr[]={1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.1};
    const char *p1="Hello";
    const char *p2="World";
    std::cout << "整型数组的和：" << sum(iArr,10) << "\n";
    std::cout << "浮点数组的和：" << sum(dArr,10) << "\n";
    std::cout << "整型和浮点数相加和：" << sum(iArr,10, dArr,10) << "\n";
    std::cout << "字符数组连接:" << sum(p1, p2);
    return 0;
}