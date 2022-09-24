#include <iostream>
#include <memory>

class Person
{
public:
    std::string name;
    int age;

public:
    Person(/* args */);
    ~Person();
};

Person::Person(/* args */)
{
    this->name = "yuri";
    this->age = 18;
    std::cout << "对象被创建\n";
}

Person::~Person()
{
    std::cout << "对象被析构\n";
}


int main(int argc, char const *argv[])
{
    std::shared_ptr hh = std::make_shared<Person>();
    std::cout << "name " << hh->name << std::endl;
    return 0;
}
