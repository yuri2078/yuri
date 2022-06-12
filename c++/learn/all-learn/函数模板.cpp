#include <iostream>
//声明模板 后面跟着函数则是函数模板
template<typename T>  //这里可以是typename 也可以是class
//并且他没有默认的类型
T max(T a, T b)
{
    return a > b ? a : b;
}

int max(int a, int b)
{
    std::cout << "\n普通的调用！\n";
    return a > b ? a : b;
}

template<typename T>

void fun1()
{
    std::cout << "\n没有T 的模板函数\n";
}


template<typename T>
void fun2(T a, T b)
{
    std::cout << "\n没有T 的模板函数\n";
}
void fun2(int a, int b)
{
    std::cout << "\n普通函数调用!s\n";
}

template<typename T>
void sort(T &a)
{
    int len = sizeof(a) / sizeof(a[0]);
    std::cout << "\n没有排序的结果是：\n";
    for (int i = 0; i < len;i++)
    {
        std::cout << a[i] << "  ";
    }
    for(int i = 1; i < len;i++)
    {
        T x;
        x[0] = a[i];
        int k = i - 1;
        while(k >= 0 && x[0]<a[k])
        {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = x[0];
    }
    std::cout << "\n排序过后的结果是：\n";
    for (int i = 0; i < len;i++)
    {
        std::cout << a[i] << "  ";
    }
}

template<typename T>
void sort(T &a, int temp)
{
    int len = sizeof(a) / sizeof(a[0]);
    std::cout << "\n没有排序的结果是：\n";
    for (int i = 0; i < len;i++)
    {
        std::cout << a[i] << "  ";
    }
    for(int i = 1; i < len;i++)
    {
        T x;
        x[0] = a[i];
        int k = i - 1;
        while(k >= 0 && x[0]>a[k])
        {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = x[0];
    }
    std::cout << "\n排序过后的结果是：\n";
    for (int i = 0; i < len;i++)
    {
        std::cout << a[i] << "  ";
    }
}

class Person
{
public:
    int age;
Person(int age = 0)
{
    this->age = age;
}

};

template<typename T>  //这里可以是typename 也可以是class
bool min(T &a, T &b)
{
    if(a < b)
    {
        return true;
    }
    return false;
}


//对类进行max 对比函数
template<> bool min(Person &p1, Person &p2)
{
    if(p1.age < p2.age)
    {
        return true;
    }
    return false;
}

//当调用min 时，会优先考虑已经指定的参数类型

int main()
{
    int a = 66, b = 55;
    char c = 'c';
    double f1 = 3.214, f2 = 66.6;
    std::cout << "a 和 b 中 " << max(a, b) << " 较大\n"; //编译器自动推导数据类型
    std::cout << "f1 和 f2 中 " << max<double>(f1, f2) << " 较大\n"; //自己指定数据类型
    std::cout << "a 和 c 中 " << max<double>(a, c) << " 较大\n"; //自己指定类型转化不会报错，前提是函数采用的是 常量传递，而不是引用

    // std::cout << "a 和 f1 中 " << max(a, f1) << "较大\n";  推导出的两个数据类型不一致，报错
    // fun();当我没有用到T，T就确定不出类型，报错
    fun1<int>(); //我直接告诉他是int 就不会报错

    //实列 通用排序
    int int1[] = {1, 2, 3, 22, 33, 22, 10, 99, 23, 433};
    sort(int1);
    sort(int1,3); //函数重载,实现逆序排序

    //普通函数与模板函数

    //1、编译器会优先调用普通函数
    fun2(1,2); //此时不会报错，因为调用的是普通函数
    fun2<>(1,2); //通过空模板调用，不会报错

    //优先级
    char c1 = 'a', c2 = 'b';
    std::cout << "c1 和 c2 中 " << max(c1, c2) << " 较大\n"; //这句并没有调用普通函数，编译器选择更好的选择
    // max 普通函数是int 型，编译器觉得需要转换成int 很麻烦，就直接调用 模板函数
    std::cout << "1 和 2 中 " << max(1, 2) << " 较大\n"; //这里都是int 不存在转换，编译器就默认调用普通函数
    return 0;
}

