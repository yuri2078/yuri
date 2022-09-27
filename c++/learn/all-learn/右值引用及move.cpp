#include <iostream>
#include <memory>

class Person
{
private:
    /* data */
public:
    Person(/* args */);
    Person(const Person &&p); //移动构造函数
    ~Person();
};

Person::Person(/* args */)
{
    std::cout << "类创建\n";
}

Person::~Person()
{
    std::cout << "类析构\n";
}

Person::Person(const Person &&p)
{
    std::cout << "调用移动构造函数\n";
    //当那个值不再使用时可以调用移动构造函数
    //系统会直接把原来的值移动到新的地方，避免了拷贝的时间
    //复制完了一般不能再使用
}

int main(int argc, char const *argv[])
{
    Person p;
    Person pp = std::move(p); 
    return 0;
}
