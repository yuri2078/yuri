#include <iostream>

class Person 
{
public:
    int x;
    int y;
    Person(int x, int y) { x = this->x = x; this->y = y; }
    // Person operator+ (Person &p)
    // {
    //     Person temp(0,0);
    //     temp.x = this->x + p.x;
    //     temp.y = this->y + p.y;
    //     return temp;
    // }
    //调用方法 Person p3 = p1.operator+(p2);
    //p3 = p1.operator+(p2);//等同于上一条 




    // void operator<< (std::ostream &cout)
    // {
    //     std::cout << x << "   " << y << "\n";
    // }    
    // p4 << std::cout; 调用方法
    // p4.operator<<(std::cout);等同于上一条
};

//等同于上面那个代码，不过这个只能使用p1+p2调用或者 operator（p1，p2）
Person  operator+ (Person &p1, Person &p2)
{
    Person temp(0,0);
    temp.x = p1.x + p2.x;
    temp.y = p1.y + p2.y;
    return temp;
}
//cout 只能有一个，所以这里只能是引用
std::ostream & operator<< (const std::ostream  &cout, const Person &p)
{
    std::cout << "p.x = " << p.x << "\n";
    std::cout << "p.y = " << p.y << "\n";
    return std::cout; //继续返回cout，可以继续打印
}

std::istream & operator>> (const std::istream &cin, Person &p)
{
    std::cin >> p.x >> p.y;
    return std::cin; //继续返回cin，可以继续打印
}


int operator< (Person &a, Person &b)
{
    return a.x > b.x;
}

int main()
{ 
    Person p1(10, 20), p2(30, 40);
    Person p3 = p1 + p2;
    std::cout << p3.x << "   " << p3.y << "\n";
    std::cout << p3;
    std::cin >> p3;
    std::cout << p3;
    if(p1 < p3)
        std::cout << "hello";
    return 0;
}