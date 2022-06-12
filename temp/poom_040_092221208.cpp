#include <iostream>
struct Data
{
    int a;
    char ch;
};

template <class T>
T mymax(const T &t1, const T &t2)
{
    return t1 > t2 ? t1 : t2;
}

struct Data mymax(const Data &d1, const Data &d2)
{
    Data temp =
    {
        d1.a > d2.a ? d1.a : d2.a,
        d1.ch > d2.ch ? d1.ch : d2.ch
    };
    return temp;
}

int main()
{
    Data a = { 4,'c'}, b={ 59,'t'};
    std::cout << "2��15�����ֵ��: " << mymax(2, 15) << "\n";
    std::cout << "b��x�����ֵ��: " << mymax('b', 'x') << "\n";
    std::cout << "<" << a.a << "," << a.ch << ">��<" << b.a << "," << b.ch << ">�����ֵ�ǣ�";
    std::cout << "<" << mymax(a,b).a << "," << mymax(a,b).ch << ">\n";
    return 0;
}
