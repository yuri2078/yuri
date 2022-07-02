#include <iostream>
#include <list>

bool mySort_1(const int &x,const int &y)
{
    return x > y;
}

class Person
{
private:
    int age;
public:
    Person(int age)
    {
        this->age = age;
    }

    friend bool mySort_2(const Person &p1, const Person &p2);

    void display(void)
    {
        std::cout << age << " ";
    }
};

bool mySort_2(const Person &p1, const Person &p2)
{
    return p1.age > p2.age;
}

int main()
{
    std::list<int> l; //初始化链表
    l.resize(0); //更改大小，为后续的是独居留位置=
    for (int i = 0; i < 20;i++)
    {
        l.push_back(i % 11);
    }


    //因为链表不是连续的空间，所以不支持随机访问

    // std::cout << *(begin + 1) << "\n";
    //错误，不支持 + 1 跳转

    // std::cout << l.at(0) << "\n";//错误 不支持at访问数据
    // std::cout << l.[0] << "\n"; //错误  不支持[]方式访问数据
    std::cout << "第一个元素为： " << l.front() << "\n";
    std::cout << "最后一个元素为： " << l.back() << "\n";



    l.push_back(123);
    l.pop_back(); //尾部

    l.push_front(12345); //头部
    l.pop_front();


    std::cout << "\n";
    std::cout << "list 的元素个数是: " << l.size() << "\n";

    l.remove(6); //删除与 相匹配的所有元素
    std::cout << "删除 6 之后 list 的元素个数是: " << l.size() << "\n";
    std::cout << "\n";

    std::cout << "原数据：\n";
    for (std::list<int>::iterator begin = l.begin(); begin != l.end();begin++)
    {
        std::cout << *begin << " ";
    }
    std::cout << "\n";

    l.sort();

    std::cout << "排序后数据：\n";
    for (std::list<int>::iterator begin = l.begin(); begin != l.end();begin++)
    {
        std::cout << *begin << " ";
    }
    std::cout << "\n";

    std::cout << "自定义排序规则：\n";
    l.sort(mySort_1);
    for (std::list<int>::iterator begin = l.begin(); begin != l.end();begin++)
    {
        std::cout << *begin << " ";
    }
    std::cout << "\n";

    std::cout << "反转后的数据\n";


    l.reverse();
    for (std::list<int>::iterator begin = l.begin(); begin != l.end();begin++)
    {
        std::cout << *begin << " ";
    }
    std::cout << "\n";

//person 年龄排序

    std::list<Person> list_person;
    for (int i = 0; i < 10;i++)
    {
        Person p(i % 4);
        list_person.push_back(p);
    }

    std::cout << "原来的数据为:\n";
    for (std::list<Person>::iterator begin = list_person.begin(); begin != list_person.end();begin++)
    {
        (*begin).display();
    }
    std::cout << "\n";

    std::cout << "排序后的数据为:\n";
    list_person.sort(mySort_2);
    for (std::list<Person>::iterator begin = list_person.begin(); begin != list_person.end();begin++)
    {
        (*begin).display();
    }
    std::cout << "\n";
    
    return 0;


    // * 尾插   --- push_back
    // * 尾删   --- pop_back
    // * 头插   --- push_front
    // * 头删   --- pop_front
    // * 插入   --- insert
    // * 删除   --- erase
    // * 移除   --- remove
    // * 清空   --- clear
}